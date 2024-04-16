/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children_process_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:12:55 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/16 15:34:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	fisrt_pipe(t_pipeb *my_pipe)
{
	close(my_pipe->outfile);
	tube_in_out(my_pipe->infile, my_pipe->tube[1]);
	close(my_pipe->infile);
}

void	last_pipe(t_pipeb *my_pipe)
{
	close(my_pipe->infile);
	tube_in_out(my_pipe->tube[2 * my_pipe->index - 2], my_pipe->outfile);
	close(my_pipe->outfile);
}

void	intermediate_pipe(t_pipeb *my_pipe)
{
	close(my_pipe->infile);
	close(my_pipe->outfile);
	tube_in_out(my_pipe->tube[2 * my_pipe->index - 2], my_pipe->tube[2
		* my_pipe->index + 1]);
}
