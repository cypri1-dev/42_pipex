/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/04 12:19:41 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//char	*get_path(char **envp)

void	exit_perror(int error)
{
	if(error == ERROR_INFILE)
		perror("Error with infile!\n");
	else if (error == ERROR_OUTFILE)
		perror("Error with outfile!\n");
	else
		perror("Error with pipe!\n");
	exit(1);
	
}

void	exit_error(int error)
{
	if(error == ERROR_INPUT)
	{
		write(2, "Not enought arguments!\n", 26);
		return;
	} 
}