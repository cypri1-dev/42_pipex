/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:53:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/03 17:24:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*all includes*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

/*main structure*/

typedef struct s_pipe
{
	pid_t	pid_1;
	pid_t	pid_2;
	int tube[2];
	int	infile;
	int outfile;
	char	*paths;
	char	*cmd;
	char	**paths_cmd;
	char	**args_cmd;
}			t_pipe;

/*enum garbage for error*/

enum	e_state
{
	ERROR_INPUT = 1,
	ERROR_INFILE = 2,
};

/*all prototyopes*/

void	exit_error(enum e_state error);

#endif