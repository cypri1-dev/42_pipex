/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:27:58 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/11 16:04:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	parse_args(char *first_arg, t_pipeb *pipe)
{
	if(first_arg && ft_strncmp("here_doc", first_arg, 9) == 0)
	{
		pipe->here_doc = 1;
		return (SIX_ARGS_INPUT);
	}
	else
	{
		pipe->here_doc = 0;
		return (FIVE_ARGS_INPUT);	
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipeb pipe;
	
	(void)envp;
	if(argc < parse_args(argv[1], &pipe))
		exit_error("Error\nInvalid args detected!\n");
	//printf("here_doc --> %d (1-yes | 0-no)\n", pipe.here_doc);
	init_infile(argv, &pipe);
	return (0);
}