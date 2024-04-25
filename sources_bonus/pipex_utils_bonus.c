/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 12:15:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/25 16:27:22 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], 4))
		i++;
	if (ft_strncmp("PATH", envp[i], 4) == 0)
		return (ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5));
	else
		return (NULL);
}

void	here_doc_infile(char *argv, t_pipeb *my_pipe)
{
	int		fd;
	char	*buffer;

	buffer = NULL;
	fd = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		exit_error("Error\nFailed to open temporary file!\n");
	while (1)
	{
		write(1, "heredoc>", 9);
		if (get_next_line(0, &buffer) <= 0)
			break ;
		if (!buffer || ft_strncmp(argv, buffer, ft_strlen(argv) + 1) == 0)
		{
			write(fd, "\n", 1);
			break ;
		}
		(write(fd, buffer, ft_strlen(buffer)), write(fd, "\n", 1),
			free(buffer));
	}
	(free(buffer), close(fd));
	my_pipe->infile = open(".here_doc_tmp", O_RDONLY);
	if (my_pipe->infile < 0)
		(unlink(".here_doc_tmp"),
			exit_error("Error\nFailed to open temporary input file!\n"));
}

void	init_outfile(char *argv, t_pipeb *my_pipe)
{
	if (my_pipe->here_doc)
		my_pipe->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		my_pipe->outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (my_pipe->outfile < 0)
	{
		close(my_pipe->infile);
		exit_error("Error\nFailed to open output file!\n");
	}
}

void	init_infile(char **argv, t_pipeb *my_pipe)
{
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		here_doc_infile(argv[2], my_pipe);
	else
	{
		my_pipe->infile = open(argv[1], O_RDONLY);
		if (my_pipe->infile < 0)
			exit_error("Error\nFailed to open intput file!\n");
	}
}

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
