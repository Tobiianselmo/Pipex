/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:45:47 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:46:03 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc < 6)
		error_pipex("Error with arguments");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (pipe(fd) == -1)
			error_pipex("Error creating pipe");
		do_here_doc(argv, fd);
		create_here_doc_process(argc, argv, envp, fd);
	}
	else
	{
		if (pipe(fd) == -1)
			error_pipex("Error creating pipe");
		create_process(argc, argv, envp, fd);
	}
}
