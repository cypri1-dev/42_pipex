/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:36:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/20 17:21:10 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_children_process(t_pipeb *my_pipe)
{
	int	i;

	i = 0;
	if (my_pipe->args_cmd)
	{
		while (my_pipe->args_cmd[i])
		{
			free(my_pipe->args_cmd[i]);
			i++;
		}
		free(my_pipe->args_cmd);
	}
	if (my_pipe->paths_cmd)
		free(my_pipe->cmd);
}

static char	*make_cmd(char **paths, char *cmd)
{
	char	*final_cmd;
	char	*tmp;
	int		i;

	i = 0;
	if (cmd == NULL)
		return (NULL);
	if (paths == NULL)
		return (cmd);
	if (access(cmd, F_OK | X_OK) == 0)
	{
		final_cmd = cmd;
		return (final_cmd);
	}
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		final_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(final_cmd, F_OK | X_OK) == 0)
			return (final_cmd);
		free(final_cmd);
		i++;
	}
	return (NULL);
}

void	close_tubes(t_pipeb *my_pipe)
{
	int	i;

	i = 0;
	if (my_pipe->tube)
	{
		while (i < my_pipe->nb_pipe)
		{
			close(my_pipe->tube[i]);
			i++;
		}
	}
}

void	tube_in_out(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}

void	children_process(t_pipeb my_pipeb, char **argv, char **envp)
{
	my_pipeb.pid = fork();
	if (my_pipeb.pid == -1)
		(close_tubes(&my_pipeb), free_children_process(&my_pipeb), exit(1));
	if (!my_pipeb.pid)
	{
		if (my_pipeb.index == 0)
			fisrt_pipe(&my_pipeb);
		else if (my_pipeb.index == my_pipeb.nb_cmd - 1)
			last_pipe(&my_pipeb);
		else
			intermediate_pipe(&my_pipeb);
		close_tubes(&my_pipeb);
		my_pipeb.args_cmd = ft_split(argv[2 + my_pipeb.here_doc
				+ my_pipeb.index], ' ');
		my_pipeb.cmd = make_cmd(my_pipeb.paths_cmd, my_pipeb.args_cmd[0]);
		execve(my_pipeb.cmd, my_pipeb.args_cmd, envp);
		error_cmd(&my_pipeb);
	}
}
