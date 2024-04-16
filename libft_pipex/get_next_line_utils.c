/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:45:09 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/16 15:31:08 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pipex.h"

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
