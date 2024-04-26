/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:03 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:31:38 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_cmd(char *argv, char **path)
{
	char	**cmd;
	char	*aux;
	char	*cmd_and_path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	aux = ft_strjoin(path[0], "/");
	cmd_and_path = ft_strjoin(aux, cmd[0]);
	while (path[++i])
	{
		if (check_access(cmd_and_path, cmd, aux) == 0)
			return (cmd_and_path);
		else
		{
			free(aux);
			free(cmd_and_path);
			aux = ft_strjoin(path[i], "/");
			cmd_and_path = ft_strjoin(aux, cmd[0]);
		}
	}
	if (aux)
		free(aux);
	free_matrix(cmd);
	return (free(cmd_and_path), NULL);
}

char	**split_cmd(char *argv)
{
	int		count;
	char	**cmd_splited;
	char	**aux;

	count = quantity_char(argv, '\'');
	if (count == 2)
	{
		aux = ft_split(argv, '\'');
		cmd_splited = split_pipex(argv, aux);
		free_matrix(aux);
		return (cmd_splited);
	}
	else
	{
		cmd_splited = ft_split(argv, ' ');
		return (cmd_splited);
	}
}

char	**split_pipex(char *argv, char **aux)
{
	char	**cmd;
	int		i;

	i = 1;
	cmd = (char **)malloc(sizeof(char *) * count_words(argv, '\'') + 1);
	if (!cmd)
		return (NULL);
	cmd[0] = ft_strtrim(aux[0], " ");
	while (aux[i])
	{
		cmd[i] = ft_strdup(aux[i]);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
