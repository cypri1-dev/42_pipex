/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:57:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/22 14:11:20 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	error_execve(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	while (my_pipe->args_cmd && my_pipe->args_cmd[i])
	{
		free(my_pipe->args_cmd[i]);
		i++;
	}
	if (my_pipe->args_cmd)
		free(my_pipe->args_cmd);
	if (my_pipe->paths)
		free(my_pipe->final_cmd);
	exit(1);
}

static char	*make_cmd(t_pipe *my_pipe, char **paths, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	if (paths == NULL)
		return (cmd);
	if (cmd == NULL)
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
	{
		my_pipe->final_cmd = cmd;
		return (my_pipe->final_cmd);
	}
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		my_pipe->final_cmd = ft_strjoin(tmp, cmd);
		if (!my_pipe->final_cmd)
			return (free(tmp), NULL);
		free(tmp);
		if (access(my_pipe->final_cmd, F_OK | X_OK) == 0)
			return (my_pipe->final_cmd);
		free(my_pipe->final_cmd);
	}
	return (NULL);
}

void	first_child_process(t_pipe my_pipe, char **argv, char **envp)
{
	int	i;

	i = 0;
	dup2(my_pipe.infile, STDIN_FILENO);
	(close(my_pipe.infile), close(my_pipe.outfile), close(my_pipe.tube[0]));
	(dup2(my_pipe.tube[1], STDOUT_FILENO), close(my_pipe.tube[1]));
	my_pipe.args_cmd = ft_split(argv[2], ' ');
	my_pipe.cmd = make_cmd(&my_pipe, my_pipe.paths_cmd, my_pipe.args_cmd[0]);
	if (!my_pipe.cmd)
	{
		free_child_process(&my_pipe);
		while (my_pipe.paths_cmd[i])
		{
			free(my_pipe.paths_cmd[i]);
			i++;
		}
		free(my_pipe.paths_cmd);
		free(my_pipe.paths);
		exit_error("Error\nFailed to execute first command!\n");
	}
	execve(my_pipe.cmd, my_pipe.args_cmd, envp);
	error_execve(&my_pipe);
}

void	second_child_process(t_pipe my_pipe, char **argv, char **envp)
{
	int	i;

	i = 0;
	(dup2(my_pipe.tube[0], STDIN_FILENO), close(my_pipe.tube[0]),
		close(my_pipe.tube[1]));
	dup2(my_pipe.outfile, STDOUT_FILENO);
	(close(my_pipe.outfile), close(my_pipe.infile));
	my_pipe.args_cmd = ft_split(argv[3], ' ');
	my_pipe.cmd = make_cmd(&my_pipe, my_pipe.paths_cmd, my_pipe.args_cmd[0]);
	if (!my_pipe.cmd)
	{
		free_child_process(&my_pipe);
		while (my_pipe.paths_cmd[i])
		{
			free(my_pipe.paths_cmd[i]);
			i++;
		}
		(free(my_pipe.paths_cmd), free(my_pipe.paths));
		exit_error("Error\nFailed to execute second command!\n");
	}
	execve(my_pipe.cmd, my_pipe.args_cmd, envp);
	error_execve(&my_pipe);
}
