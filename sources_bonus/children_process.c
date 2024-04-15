/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:36:51 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/15 20:50:49 by cyferrei         ###   ########.fr       */
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
	if (access(cmd, F_OK | X_OK) == 0)
	{
		final_cmd = cmd;
		return final_cmd;
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
	int i;

	i = 0;
	while(i < my_pipe->nb_pipe)
	{
		close(my_pipe->tube[i]);
		i++;
	}
}

static void tube_in_out(int in, int out)
{
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}

void	children_process(t_pipeb my_pipeb, char **argv, char **envp)
{
	my_pipeb.pid = fork();
	if (!my_pipeb.pid)
	{
		if (my_pipeb.index == 0)
		{
			close(my_pipeb.outfile);
			tube_in_out(my_pipeb.infile, my_pipeb.tube[1]);
			close(my_pipeb.infile);
		}
		else if (my_pipeb.index == my_pipeb.nb_cmd -1)
		{
			close(my_pipeb.infile);
			tube_in_out(my_pipeb.tube[2 * my_pipeb.index - 2], my_pipeb.outfile);
			close(my_pipeb.outfile);
		}
		else
		{
			close(my_pipeb.infile);
			close(my_pipeb.outfile);
			tube_in_out(my_pipeb.tube[2 * my_pipeb.index - 2], my_pipeb.tube[2 * my_pipeb.index + 1]);
		}
		close_tubes(&my_pipeb);
		my_pipeb.args_cmd = ft_split(argv[2 + my_pipeb.here_doc + my_pipeb.index], ' ');
		my_pipeb.cmd = make_cmd(my_pipeb.paths_cmd, my_pipeb.args_cmd[0]);
		if(my_pipeb.cmd == NULL)
		{
			ft_putstr_fd("Command not found: ", 2);
			write(2, my_pipeb.args_cmd[0], ft_strlen(my_pipeb.args_cmd[0]));
			free_children_process(&my_pipeb);
			exit(1);
		}
		execve(my_pipeb.cmd, my_pipeb.args_cmd, envp);
	}	
}