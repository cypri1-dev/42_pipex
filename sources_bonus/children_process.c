/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:36:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/17 00:13:53 by cyprien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_children_process(t_pipeb *my_pipe)
{
	int	i;

	i = 0;
	while (my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
	i = 0;
	while (my_pipe->args_cmd[i])
	{
		free(my_pipe->args_cmd[i]);
		i++;
	}
	free(my_pipe->args_cmd);
	free(my_pipe->cmd);
	free(my_pipe->tube);
	free(my_pipe->path_env);
}

static char	*make_cmd(char **paths, char *cmd)
{
	char	*final_cmd;
	char	*tmp;
	int		i;

	i = 0;
	if(cmd == NULL)
		return (NULL);
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
	while (i < my_pipe->nb_pipe)
	{
		close(my_pipe->tube[i]);
		i++;
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
		if (my_pipeb.cmd == NULL)
		{
			write(2, "Command not found: ", 20);
			if(my_pipeb.args_cmd[0] != NULL)
				write(2, my_pipeb.args_cmd[0], ft_strlen(my_pipeb.args_cmd[0]));
			write(2, "\n", 1);
			free_children_process(&my_pipeb);
			exit(1);
		}
		execve(my_pipeb.cmd, my_pipeb.args_cmd, envp);
	}
}
