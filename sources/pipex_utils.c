/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyprien <cyprien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/28 21:18:40 by cyprien          ###   ########.fr       */
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
	i = 0;
	if (my_pipe->paths_cmd != NULL)
	{
		while (my_pipe->paths_cmd && my_pipe->paths_cmd[i])
		{
			free(my_pipe->paths_cmd[i]);
			i++;
		}
		free(my_pipe->paths_cmd);
	}
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

void	is_a_dir(char *argv)
{
	if (argv != NULL)
		write(2, argv, ft_strlen(argv));
	write(2, ": Is a directory\n", 18);
	exit(1);
}

int	check_dir(char *file)
{
	int	res;

	res = open(file, O_DIRECTORY);
	if (access(file, X_OK) == 0 && res != -1)
	{
		close(res);
		return (-1);
	}
	if (access(file, X_OK) == 0 && access(file, F_OK) == 0)
	{
		return (0);
	}
	return (0);
}
