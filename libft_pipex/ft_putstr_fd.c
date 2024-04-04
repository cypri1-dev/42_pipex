/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puststr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:43:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 13:45:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	
	i = 0;
	if (!s)
		return;
	while(s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}