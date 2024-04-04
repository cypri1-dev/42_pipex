/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 12:38:11 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe my_pipe;
	
	if (argc != 5)
	{
		exit_error(ERROR_INPUT);
		return (0);
	}
	my_pipe.infile = open(argv[1], O_RDONLY);
	if (my_pipe.infile < 0)
		exit_perror(ERROR_INFILE);
	my_pipe.outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	//printf("d = %d\n", my_pipe.outfile);
	if (my_pipe.outfile < 0)
	{
		close(my_pipe.infile);
		exit_perror(ERROR_OUTFILE);
	}
	close(my_pipe.infile);
	close(my_pipe.outfile);
	// if (pipe(my_pipe.tube) < 0)
	// 	exit_perror(ERROR_PIPE);
	return (0);
}