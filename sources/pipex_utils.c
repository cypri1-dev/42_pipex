/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/17 19:36:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_parent_process(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	while (my_pipe->paths_cmd && my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
	free(my_pipe->paths);
}

void	free_child_process(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	while (my_pipe->args_cmd[i])
	{
		free(my_pipe->args_cmd[i]);
		i++;
	}
	free(my_pipe->args_cmd);
}

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4))
		i++;
	if (ft_strncmp("PATH", envp[i], 4) == 0)
		return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
	else
		return (NULL);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
