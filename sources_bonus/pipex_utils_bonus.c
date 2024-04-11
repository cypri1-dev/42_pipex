/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:15:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/11 18:40:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc_infile(char *argv, t_pipeb *pipe)
{
	int fd;
	char *buffer;

	fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(fd < 0)
		exit_error("Error!\nError with here_doc\n");
	while(1)
	{
		write(1, "heredoc>", 9);
		if(get_next_line(0, &buffer) < 0)
			exit(1);
		if(ft_strncmp(argv, buffer, ft_strlen(argv) + 1) == 0)
			break;
		write(fd, buffer, ft_strlen(buffer));
		write(fd, "\n", 1);
		free(buffer);
	}
	free(buffer);
	close(fd);
	pipe->infile = open(".here_doc_tmp", O_RDONLY);
	if(pipe->infile < 0)
	{
		unlink(".here_doc_tmp");
		exit_error("Error\nError with heredoc!\n");
	}
}

void	init_outfile(char *argv, t_pipeb *pipe)
{
	if(pipe->here_doc)
		pipe->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipe->outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(pipe->outfile < 0)
		exit_error("Error\nError with outfile!\n");
}

void	init_infile(char **argv, t_pipeb *pipe)
{
	if(ft_strncmp("here_doc", argv[1], 9) == 0)
		here_doc_infile(argv[2], pipe);
	else
	{	
		pipe->infile = open(argv[1], O_RDONLY);
		if(pipe->infile < 0)
			exit_error("Error\nError with infile !\n");
	}
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(2);
}