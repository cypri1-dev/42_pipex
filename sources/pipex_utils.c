/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/03 17:32:06 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_error(enum e_state error)
{
	if(error == ERROR_INPUT)
	{
		write(2, "Not enought arguments!\n", 26);
		return;
	} 
	else if(error = ERROR_INFILE)
	{
		write(2, "Error with infile!\n", 19);
		return;
	}
}