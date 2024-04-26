/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:57:30 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 16:29:09 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	get_here_doc(char *limitator, int *fd)
{
	char	*line;
	size_t	size;

	size = ft_strlen(limitator);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		error_pipex("Error duplicating fd[1]");
	while (1)
	{
		line = get_next_line(0);
		if (ft_strncmp(line, limitator, size) == 0 && line[size] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, 1);
		free(line);
	}
}

void	do_here_doc(char **argv, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error_pipex("Error creating process");
	else if (pid == 0)
	{
		get_here_doc(argv[2], fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (dup2(fd[0], 0) == -1)
			error_pipex("Error duplicating fd");
		close(fd[1]);
		waitpid(pid, NULL, 0);
	}
}

void	create_here_doc_process(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	pid_t	last_process;

	i = 2;
	while (++i < argc - 2)
		mid_process(argv[i], envp, fd);
	last_process = fork();
	if (last_process == -1)
		error_pipex("Error creating last process");
	if (last_process == 0)
		create_last_bonus_process(fd, argv[argc - 2], envp, argv[argc - 1]);
	waitpid(last_process, NULL, 0);
}

void	create_last_bonus_process(int *fd, char *argv, char **envp, char *file)
{
	int		new_file;
	char	**path;
	char	*cmd;

	new_file = create_bonus_file(file);
	if (new_file == -1)
		error_pipex("Error creating new file");
	if (dup2(fd[0], 0) == -1)
		error_pipex("Error duplicating fd[0]");
	close(fd[0]);
	if (dup2(new_file, 1) == -1)
		error_pipex("Error duplicating new file");
	close(new_file);
	path = get_path(envp);
	if (!path)
		error_pipex("Error getting path");
	cmd = find_cmd(argv, path);
	free_matrix(path);
	check_command(cmd, argv);
	exec_bonus(cmd, envp, argv);
}
