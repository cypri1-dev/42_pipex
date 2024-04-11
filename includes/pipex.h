/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:53:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/11 15:42:23 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

typedef struct s_pipe
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	*cmd;
	char	**paths_cmd;
	char	**args_cmd;
}			t_pipe;

/*all prototyopes*/

void		exit_error(char *str);
int			check_env(char **envp);
char		*get_path(char **envp);
void		first_child_process(t_pipe my_pipe, char **argv, char **envp);
void		second_child_process(t_pipe my_pipe, char **argv, char **envp);
void		free_child_process(t_pipe *my_pipe);
void		free_parent_process(t_pipe *my_pipe);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strstr(char *haystack, char *needle);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *str);
char		*ft_substr(char const *s, int start, int len);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);

#endif