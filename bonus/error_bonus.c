/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:45:58 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/25 18:44:48 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_command(char *message, char *cmd)
{
	char	*str;

	str = ft_strjoin(message, cmd);
	ft_putendl_fd(str, 2);
	free(str);
	exit(EXIT_FAILURE);
}

void	error_pipex(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}
