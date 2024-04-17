/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:34:43 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/17 14:31:39 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	if (n < 1)
		return (-1);
	while ((s1[i] && s2[i]) && (s1[i] == s2[i] && i < (n - 1)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
