/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:19:54 by tanselmo          #+#    #+#             */
/*   Updated: 2024/04/25 15:26:56 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	duplicate_two(int f_a, int f_b, int s_a, int s_b)
{
	if (dup2(f_a, f_b) == -1)
		error_pipex("Error duplicating fd");
	if (dup2(s_a, s_b) == -1)
		error_pipex("Error duplicating fd");
}
