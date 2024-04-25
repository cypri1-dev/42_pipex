/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/25 14:11:45 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	init_files(t_pipe *my_pipe, char **argv, int argc)
{
	my_pipe->exit_status = 0;
	my_pipe->sigpipe = 0;
	if (check_dir(argv[argc - 1]) == -1)
		is_a_dir(argv[argc - 1]);
	if (check_dir(argv[1]) == -1)
		is_a_dir(argv[1]);
	my_pipe->outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (my_pipe->outfile < 0)
		file_not_foud(my_pipe, argv[argc - 1]);
	my_pipe->infile = open(argv[1], O_RDONLY);
	if (my_pipe->infile < 0)
		file_not_foud(my_pipe, argv[1]);
}

static void	parse_pipex(int argc)
{
	if (argc != 5)
		exit_error("Error\nInvalid numbers of arguments!\n");
	return ;
}

static void	free_cmd(t_pipe *my_pipe)
{
	int	i;

	i = 0;
	while (my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
}

static void	close_pipe(t_pipe *my_pipe)
{
	close(my_pipe->tube[0]);
	close(my_pipe->tube[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	my_pipe;

	(parse_pipex(argc), init_files(&my_pipe, argv, argc));
	if (pipe(my_pipe.tube) < 0)
		exit_error("Error\nFailed to create pipe!\n");
	my_pipe.paths = get_path(envp);
	my_pipe.paths_cmd = ft_split(my_pipe.paths, ':');
	my_pipe.pid_1 = fork();
	if (my_pipe.pid_1 == -1)
		free_parent_process(&my_pipe);
	if (my_pipe.pid_1 == 0)
		first_child_process(my_pipe, argv, envp);
	my_pipe.pid_2 = fork();
	if (my_pipe.pid_2 == -1)
		free_parent_process(&my_pipe);
	if (my_pipe.pid_2 == 0)
		second_child_process(my_pipe, argv, envp);
	(close_pipe(&my_pipe), waitpid(my_pipe.pid_1, &my_pipe.exit_status, 0));
	if (!WIFEXITED(my_pipe.exit_status))
		my_pipe.sigpipe = 1;
	waitpid(my_pipe.pid_2, &my_pipe.exit_status, 0);
	if (WIFEXITED(my_pipe.exit_status) && my_pipe.sigpipe)
		my_pipe.exit_status = 130 << 8;
	free_parent_process(&my_pipe);
	return (WEXITSTATUS(my_pipe.exit_status));
}
