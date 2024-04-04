/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 15:21:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe my_pipe;
	
	if(!check_env(envp))
		exit_error("Error\nMissing environnement !\n");
	//printf("test");
	if (argc != 5)
		exit_error("Error\nNot enought arguments !\n");
	my_pipe.infile = open(argv[1], O_RDONLY);
	if (my_pipe.infile < 0)
		exit_error("Error\nError with intfile !\n");
	my_pipe.outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	//printf("d = %d\n", my_pipe.outfile);
	if (my_pipe.outfile < 0)
	{
		close(my_pipe.infile);
		exit_error("Error\nWError with outfile !\n");
	}
	my_pipe.paths = get_path(envp);
	printf("path --> %s\n", my_pipe.paths);
	close(my_pipe.infile);
	close(my_pipe.outfile);
	free(my_pipe.paths);
	// if (pipe(my_pipe.tube) < 0)
	// 	exit_perror(ERROR_PIPE);
	return (0);
}
