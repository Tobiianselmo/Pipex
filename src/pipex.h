/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:52:16 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 13:26:41 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

//----------------------CREATE PROCCESSES-----------------------//
void	create_process(int *fd, char **argv, char **envp);
void	create_child_process(int *fd, char **argv, char **envp);
void	create_second_child_process(int *fd, char **argv, char **envp);
//---------------------------ERROR------------------------------//
void	error_pipex(char *s);
void	error_command(char *message, char *cmd);
//---------------------------UTILS------------------------------//
void	free_matrix(char **matrix);
char	**get_path(char **envp);
//-------------------------COMMAND------------------------------//
char	*find_cmd(char *argv, char **path);
char	**split_cmd(char *argv);
char	**split_pipex(char *argv, char **aux);
//------------------------UTILS_COMMAND-------------------------//
int		quantity_char(char *s, int c);
int		check_access(char *cmd_path, char **cmd, char *aux);
int		count_words(char *str, char c);

#endif