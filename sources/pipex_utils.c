/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 15:15:33 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path(char **envp)
{
	int i = 0;
	
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	return(ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
}

int	check_env(char **envp)
{
	const char	*env = "USER";
	char		*val_va;
	int			i;

	val_va = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strstr(envp[i], (char *)env) == envp[i])
		{
			val_va = ft_strchr(envp[i], '=') + 1;
			break ;
		}
		i++;
	}
	if (val_va == NULL)
		return (0);
	else
		return (1);
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(2);
}
