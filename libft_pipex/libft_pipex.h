/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:32:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/16 15:29:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PIPEX_H
# define LIBFT_PIPEX_H

/*All includes*/

# define BUFFER_SIZE 1024
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*all prototypes functions*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strchr(char *s, int c);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, int start, int len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_calloc(size_t nmeb, size_t size);
int		get_next_line(int fd, char **line);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

#endif