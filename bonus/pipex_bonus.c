/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:12 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 16:28:16 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_first_process(int *fd, char **argv, char **envp)
{
	int		file;
	char	**path;
	char	*cmd;

	close(fd[0]);
	file = open_file(argv[1]);
	if (dup2(file, 0) == -1)
		error_pipex("Error duplicating file\n");
	close(file);
	if (dup2(fd[1], 1) == -1)
		error_pipex("Error duplicating fd[1]\n");
	close(fd[1]);
	path = get_path(envp);
	if (!path)
		error_pipex("Error getting path\n");
	cmd = find_cmd(argv[2], path);
	free_matrix(path);
	check_command(cmd, argv[2]);
	exec_bonus(cmd, envp, argv[2]);
}

void	mid_process(char *argv, char **envp, int *fd)
{
	pid_t	child;
	int		new_pipe[2];
	char	**path;
	char	*cmd;

	if (pipe(new_pipe) == -1)
		error_pipex("Error creating pipe");
	child = fork();
	if (child == -1)
		error_pipex("Error creating process");
	if (child == 0)
	{
		close_two(fd[1], new_pipe[0]);
		duplicate_two(fd[0], 0, new_pipe[1], 1);
		close_two(fd[0], new_pipe[1]);
		path = get_path(envp);
		cmd = find_cmd(argv, path);
		free_matrix(path);
		check_command(cmd, argv);
		exec_bonus(cmd, envp, argv);
		exit(0);
	}
	close(new_pipe[1]);
	waitpid(child, NULL, 0);
	change_fd_value(fd, new_pipe);
}

void	create_last_process(int *fd, char *argv, char **envp, char *file)
{
	int		new_file;
	char	**path;
	char	*cmd;

	new_file = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

void	create_process(int argc, char **argv, char **envp, int *fd)
{
	int		i;
	pid_t	first_process;
	pid_t	last_process;

	i = 2;
	first_process = fork();
	if (first_process == -1)
		error_pipex("Error creating first process");
	if (first_process == 0)
		create_first_process(fd, argv, envp);
	close(fd[1]);
	waitpid(first_process, NULL, 0);
	while (++i < argc - 2)
		mid_process(argv[i], envp, fd);
	last_process = fork();
	if (last_process == -1)
		error_pipex("Error creating last process");
	if (last_process == 0)
		create_last_process(fd, argv[argc - 2], envp, argv[argc - 1]);
	waitpid(last_process, NULL, 0);
}
