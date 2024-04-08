/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:06:43 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/08 17:03:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pipex.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (trigger == 0 && *str != c)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static char	**free_tab(char **split, int i)
{
	--i;
	while (i != 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

static char	**split_it(char *s, size_t i, char c, char **split)
{
	size_t	j;
	int		index;

	index = -1;
	j = 0;
	while (++i <= (size_t)ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (!split[j - 1])
			{
				free_tab(split, j - 1);
				return (NULL);
			}
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	split = split_it((char *)s, i, c, split);
	return (split);
}
