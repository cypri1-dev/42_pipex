/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:29:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/11 16:03:26 by cyferrei         ###   ########.fr       */
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
void	init_infile(char **argv, t_pipeb *pipe);
void	here_doc_infile(char *argv, t_pipeb *pipe);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmeb, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

int	get_next_line(int fd, char **line);
char	*obtain_rest(char *str);
char	*obtain_line(char *str);
static char	*read_file(char *final_buffer, int fd);

#endif