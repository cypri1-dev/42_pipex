/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:32:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 15:17:19 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PIPEX
# define LIBFT_PIPEX

/*All includes*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*all prototypes functions*/

int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strstr(char *haystack, char *needle);
char	*ft_strchr(const char *s, int c);
int	ft_strlen(const char *str);
char	*ft_substr(char const *s, int start, int len);

#endif