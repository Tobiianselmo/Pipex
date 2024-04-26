/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:05 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/23 16:41:49 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *argv)
{
	int	file;

	file = open(argv, O_RDONLY);
	if (file == -1)
		error_pipex("Error opening file");
	return (file);
}

int	create_file(char *argv)
{
	int	file;

	file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!file)
		error_pipex("Error creating file");
	return (file);
}

int	create_bonus_file(char *argv)
{
	int	file;

	file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (!file)
		error_pipex("Error creating bonus file");
	return (file);
}
