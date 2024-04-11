/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:29:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/11 12:17:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*all defines*/

# define SIX_ARGS_INPUT 6
# define FIVE_ARGS_INPUT 5

/*all includes*/

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

/*main structure*/

typedef struct s_pipeb
{
	pid_t pid;
	int	infile;
	int outfile;
	char **paths_cmd;
	char **args_cmd;
	char *path_env;
	char *cmd;
	int here_doc;
	int nb_cmd;
	int nb_pipe;
	int *pipe;
	int index;
}			t_pipeb;

/*all prototypes functions*/

void	exit_error(char *str);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);

#endif