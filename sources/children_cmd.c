/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:57:00 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/25 19:37:08 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	error_execve(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	if (my_pipe->cmd != NULL)
		write(2, my_pipe->cmd, ft_strlen(my_pipe->cmd));
	write(2, ": command not found\n", 21);
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
		while (!*envp && my_pipe.paths_cmd[i])
		{
			free(my_pipe.paths_cmd[i]);
			i++;
		}
		// if (my_pipe.paths_cmd)
		// free(my_pipe.paths_cmd);
		free(my_pipe.paths);
		cmd_not_foud(&my_pipe);
	}
	if (check_dir(my_pipe.cmd) == -1)
		error_execve_spec(&my_pipe);
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
	close(my_pipe.outfile);
	close(my_pipe.infile);
	my_pipe.args_cmd = ft_split(argv[3], ' ');
	my_pipe.cmd = make_cmd(&my_pipe, my_pipe.paths_cmd, my_pipe.args_cmd[0]);
	if (!my_pipe.cmd)
	{
		while (!*envp && my_pipe.paths_cmd[i])
		{
			free(my_pipe.paths_cmd[i]);
			i++;
		}
		// if (my_pipe.paths_cmd)
		// free(my_pipe.paths_cmd);
		free(my_pipe.paths);
		cmd_not_foud(&my_pipe);
	}
	if (check_dir(my_pipe.cmd) == -1)
		error_execve_spec(&my_pipe);
	execve(my_pipe.cmd, my_pipe.args_cmd, envp);
	error_execve(&my_pipe);
}
