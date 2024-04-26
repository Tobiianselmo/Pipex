/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:46:17 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/26 16:27:17 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

//----------------------CREATE PROCCESSES-----------------------//
void	create_first_process(int *fd, char **argv, char **envp);
void	mid_process(char *argv, char **envp, int *fd);
void	create_last_process(int *fd, char *argv, char **envp, char *file);
void	create_process(int argc, char **argv, char **envp, int *fd);
//---------------------------FILES------------------------------//
int		open_file(char *file);
int		create_file(char *file);
int		create_bonus_file(char *argv);
//---------------------------ERROR------------------------------//
void	error_pipex(char *message);
void	error_command(char *message, char *cmd);
//---------------------------CLOSE------------------------------//
void	close_two(int first, int second);
//--------------------------COMMAND-----------------------------//
char	*find_cmd(char *argv, char **path);
char	**split_cmd(char *argv);
char	**split_pipex(char *argv, char **aux);
//----------------------UTILS_COMMAND---------------------------//
int		check_access(char *cmd_path, char **cmd, char *aux);
int		quantity_char(char *s, int c);
int		count_words(char *str, char c);
//------------------------DUPLICATE-----------------------------//
void	duplicate_two(int f_a, int f_b, int s_a, int s_b);
//--------------------------UTILS-------------------------------//
void	free_matrix(char **matrix);
char	**get_path(char **envp);
void	change_fd_value(int *fd, int *new_pipe);
void	exec_bonus(char *cmd, char **envp, char *argv);
void	check_command(char *cmd, char *argv);
//---------------------------HERE_DOC---------------------------//
void	get_here_doc(char *limitator, int *fd);
void	do_here_doc(char **argv, int *fd);
void	create_here_doc_process(int argc, char **argv, char **envp, int *fd);
void	create_last_bonus_process(int *fd, char *argv, char **envp, char *file);

#endif