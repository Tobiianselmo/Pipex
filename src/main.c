/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:42:44 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:46:55 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
		error_pipex("Error with arguments");
	else
	{
		if (pipe(fd) == -1)
			error_pipex("Error creating pipe");
		create_process(fd, argv, envp);
	}
}
