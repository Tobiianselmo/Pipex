/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:23 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 16:27:08 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**get_path(char **envp)
{
	char	*path;
	int		i;
	int		j;
	int		check;
	char	**matrix;

	i = 0;
	j = 0;
	check = 0;
	while (envp[i] && check == 0)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_strdup(envp[i]);
			check = 1;
		}
		i++;
	}
	matrix = ft_split(&path[5], ':');
	free(path);
	return (matrix);
}

void	change_fd_value(int *fd, int *new_pipe)
{
	fd[0] = new_pipe[0];
	fd[1] = new_pipe[1];
}

void	exec_bonus(char *cmd, char **envp, char *argv)
{
	char	**cmd_split;

	cmd_split = split_cmd(argv);
	if (execve(cmd, cmd_split, envp) == -1)
	{
		free(cmd);
		free_matrix(cmd_split);
		exit(EXIT_FAILURE);
	}
}

void	check_command(char *cmd, char *argv)
{
	if (!cmd)
		error_command("zsh: command not found: ", argv);
}
