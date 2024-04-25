/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:57:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/25 16:36:56 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_execve_spec(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	if (my_pipe->cmd != NULL)
		write(2, my_pipe->cmd, ft_strlen(my_pipe->cmd));
	write(2, ": is a directory\n", 18);
	while (my_pipe->args_cmd && my_pipe->args_cmd[i])
	{
		free(my_pipe->args_cmd[i]);
		i++;
	}
	if (my_pipe->args_cmd)
		free(my_pipe->args_cmd);
	i = 0;
	while (my_pipe->paths_cmd && my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
	free(my_pipe->paths);
	exit(1);
}

void	file_not_foud(t_pipe *my_pipe, char *argv)
{
	if (argv != NULL)
		write(2, argv, ft_strlen(argv));
	write(2, ": No such file or directory\n", 29);
	if (my_pipe->outfile != -1)
		close(my_pipe->outfile);
	exit(0);
}

void	cmd_not_foud(t_pipe *my_pipe)
{
	if (my_pipe->args_cmd[0] != NULL)
		write(2, my_pipe->args_cmd[0], ft_strlen(my_pipe->args_cmd[0]));
	write(2, ": command not found\n", 21);
	free_child_process(my_pipe);
	exit(127);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(127);
}
