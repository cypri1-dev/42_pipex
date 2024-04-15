/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:27:58 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/15 20:44:20 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_parent_process(t_pipeb *my_pipe)
{
	int	i;

	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	if (my_pipe->here_doc)
		unlink(".here_doc_tmp");
	while (my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
	free(my_pipe->tube);
	free(my_pipe->path_env);
}
static void	init_tubes(t_pipeb *my_pipe)
{
	int i;

	i = 0;
	while (i < my_pipe->nb_cmd - 1)
	{
		if (pipe(my_pipe->tube + 2 * i) < 0)
			free_parent_process(my_pipe);
		i++;
	}
}

static void	close_and_free(t_pipeb *my_pipe)
{
	int i;
	
	i = 0;
	close(my_pipe->infile);
	close(my_pipe->outfile);
	if (my_pipe->here_doc)
		unlink(".here_doc_tmp");
	free(my_pipe->tube);
	exit_error("Error\nError while init command paths!\n");
}

static int	parse_args(char *first_arg, t_pipeb *my_pipe)
{
	if(first_arg && ft_strncmp("here_doc", first_arg, 9) == 0)
	{
		my_pipe->here_doc = 1;
		return (SIX_ARGS_INPUT);
	}
	else
	{
		my_pipe->here_doc = 0;
		return (FIVE_ARGS_INPUT);	
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipeb my_pipe;
	int i = 0;
	
	if(argc < parse_args(argv[1], &my_pipe))
		exit_error("Error\nInvalid args detected!\n");
	// printf("here_doc --> %d (1-yes | 0-no)\n", pipe.here_doc);
	init_infile(argv, &my_pipe);
	init_outfile(argv[argc - 1], &my_pipe);
	my_pipe.nb_cmd = argc - 3 - my_pipe.here_doc;
	// printf("nmbrs of cmd --> %d\n", my_pipe.nb_cmd);
	my_pipe.nb_pipe = 2 * (my_pipe.nb_cmd - 1);
	// printf("nmbrs of pipe --> %d\n", my_pipe.nb_pipe);
	my_pipe.tube = (int *)malloc(sizeof(int) * (my_pipe.nb_pipe));
	// printf("nmbrs of tubes --> %d\n", my_pipe.nb_pipe * 2);
	if(!my_pipe.tube)
		exit_error("Error\nError whith malloc pipes!\n");
	my_pipe.path_env = get_path(envp);
	my_pipe.paths_cmd = ft_split(my_pipe.path_env, ':');
	if(!my_pipe.paths_cmd)
		close_and_free(&my_pipe);
	init_tubes(&my_pipe);
	my_pipe.index = -1;
	while(++(my_pipe.index) < my_pipe.nb_cmd)
		children_process(my_pipe, argv, envp);
	close_tubes(&my_pipe);
	// waitpid(-1, NULL, 0);
	while (wait(NULL) > 0)
			continue; ;
	free_parent_process(&my_pipe);
	return (0);
}
