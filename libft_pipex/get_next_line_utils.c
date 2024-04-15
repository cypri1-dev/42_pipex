/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:45:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/15 16:14:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pipex.h"

// char	*gnl_strjoin(char const *s1, char const *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*new;

// 	if (!s1)
// 		s1 = ft_calloc(1, sizeof(char));
// 	if (!s1 || !s2)
// 		return (NULL);
// 	new = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i])
// 		new[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 	{
// 		new[j] = s2[i];
// 		j++;
// 		i++;
// 	}
// 	free((void *)s1);
// 	return (new);
// }

void	*ft_calloc(size_t nmeb, size_t size)
{
	char	*res;
	char	*str;
	size_t	i;

	res = malloc(nmeb * size);
	if (!res)
		return (NULL);
	str = res;
	i = 0;
	while (i < nmeb * size)
	{
		str[i] = '\0';
		i++;
	}
	return (res);
}
