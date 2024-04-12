/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/12 17:32:56 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_parent_process(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	while (my_pipe->paths_cmd[i])
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
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
}

int	check_env(char **envp)
{
	const char	*env = "PATH";
	char		*val_va;
	int			i;

	val_va = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(2);
}
