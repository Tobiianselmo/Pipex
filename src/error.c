/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:08:01 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:12:23 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_command(char *message, char *cmd)
{
	char	*str;

	str = ft_strjoin(message, cmd);
	ft_putendl_fd(str, 2);
	free(str);
	exit(EXIT_FAILURE);
}

void	error_pipex(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}
