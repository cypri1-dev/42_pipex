/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/03 17:42:43 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe pipe;
	
	if (argc != 5)
		exit_error(ERROR_INPUT);
	return (0);
	pipe.infile = open(argv[1], O_RDONLY);
	if (pipe.infile < 0)
		exit_error(ERROR_INFILE);
	pipe.outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipe.outfile < 0)
		exit_error(ERROR_OUTFILE);
}