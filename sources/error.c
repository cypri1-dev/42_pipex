/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:57:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/24 19:43:52 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	file_not_foud(t_pipe *my_pipe, char *argv)
{
	if(argv != NULL)
		write(2, argv, ft_strlen(argv));
	write(2, ": No such file or directory\n", 29);
	if(my_pipe->outfile)
		close(my_pipe->outfile);
	exit(0);
}

void	cmd_not_foud(t_pipe *my_pipe)
{
	if(my_pipe->args_cmd[0] != NULL)
		write(2, my_pipe->args_cmd[0], ft_strlen(my_pipe->args_cmd[0]));
	write(2, ": command not found\n", 21);
	free_child_process(my_pipe);
	exit(1);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}