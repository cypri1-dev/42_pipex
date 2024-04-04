/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:57:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 20:12:53 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(t_pipe my_pipe, char **argv, char **envp)
{
	dup2(my_pipe.infile, 0);
	close(my_pipe.tube[0]);
	dup2(my_pipe.tube[1], 1);
}