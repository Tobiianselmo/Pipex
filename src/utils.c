/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:46:36 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:29:26 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
