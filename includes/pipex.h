/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:53:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:55 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*definesgarbage for error*/

# define ERROR_INPUT 1
# define ERROR_INFILE 2
# define ERROR_OUTFILE 3
# define ERROR_PIPE 4

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

/*all prototyopes*/

void	exit_error(int error);
void	exit_perror(int error);

#endif