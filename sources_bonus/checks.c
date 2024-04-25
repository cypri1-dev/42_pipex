/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:48:37 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/25 16:37:19 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	cmd_not_foud(t_pipeb *my_pipeb)
{
	if (my_pipeb->args_cmd[0] != NULL)
		write(2, my_pipeb->args_cmd[0], ft_strlen(my_pipeb->args_cmd[0]));
	write(2, ": command not found\n", 21);
	free_children_process(my_pipeb);
	exit(127);
}

void	error_execve_spec(t_pipeb *my_pipeb)
{
	int	i;

	i = 0;
	if (my_pipeb->cmd != NULL)
		write(2, my_pipeb->cmd, ft_strlen(my_pipeb->cmd));
	write(2, ": is a directory\n", 18);
	while (my_pipeb->args_cmd && my_pipeb->args_cmd[i])
	{
		free(my_pipeb->args_cmd[i]);
		i++;
	}
	if (my_pipeb->args_cmd)
		free(my_pipeb->args_cmd);
	i = 0;
	while (my_pipeb->paths_cmd && my_pipeb->paths_cmd[i])
	{
		free(my_pipeb->paths_cmd[i]);
		i++;
	}
	free(my_pipeb->paths_cmd);
	free(my_pipeb->path_env);
	free(my_pipeb->tube);
	exit(1);
}

void	init_files(t_pipeb *my_pipe, char **argv, int argc)
{
	if(check_dir(argv[argc -1]) == -1)
		is_a_dir(argv[argc -1]);
	if(check_dir(argv[1]) == -1)
		is_a_dir(argv[1]);
	init_infile(argv, my_pipe);
	init_outfile(argv[argc -1], my_pipe);
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