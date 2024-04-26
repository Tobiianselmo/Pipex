/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:20:14 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:46:23 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child_process(int *fd, char **argv, char **envp)
{
	int		file;
	char	**path;
	char	*cmd;

	close(fd[0]);
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		error_pipex("Error opening file");
	if (dup2(file, 0) == -1)
		error_pipex("Error duplicating file");
	close(file);
	if (dup2(fd[1], 1) == -1)
		error_pipex("Error duplicating fd[1]");
	close(fd[1]);
	path = get_path(envp);
	if (!path)
		error_pipex("Error getting path");
	cmd = find_cmd(argv[2], path);
	free_matrix(path);
	if (!cmd)
		error_command("zsh: Command not found: ", argv[2]);
	if (execve(cmd, split_cmd(argv[2]), envp) == -1)
		free(cmd);
}

void	create_second_child_process(int *fd, char **argv, char **envp)
{
	int		new_file;
	char	**path;
	char	*cmd;

	new_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
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
	cmd = find_cmd(argv[3], path);
	if (!cmd)
		error_command("zsh: Command not found: ", argv[3]);
	if (execve(cmd, split_cmd(argv[3]), envp) == -1)
		free(cmd);
}

void	create_process(int *fd, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork();
	if (pid == -1)
		error_pipex("Error creating process");
	if (pid == 0)
	{
		create_child_process(fd, argv, envp);
		waitpid(pid, NULL, 0);
	}
	close(fd[1]);
	pid2 = fork();
	if (pid2 == -1)
		error_pipex("Error creating second process");
	if (pid2 == 0)
		create_second_child_process(fd, argv, envp);
	close(fd[0]);
	waitpid(pid2, NULL, 0);
}
