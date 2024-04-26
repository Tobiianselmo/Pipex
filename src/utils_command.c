/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:21:05 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:21:51 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	quantity_char(char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	check_access(char *cmd_path, char **cmd, char *aux)
{
	if (access(cmd_path, X_OK) == 0)
	{
		free_matrix(cmd);
		if (aux)
			free(aux);
		return (0);
	}
	return (1);
}

int	count_words(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != '\0' && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}
