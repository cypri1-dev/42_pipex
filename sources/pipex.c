/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:52:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/04/08 16:28:35 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_cmd(t_pipe *my_pipe)
{
	int i;

	i = 0;
	while (my_pipe->paths_cmd[i])
	{
		free(my_pipe->paths_cmd[i]);
		i++;
	}
	free(my_pipe->paths_cmd);
}

static void	dipslay_cmd(char **paths_cmd)
{
	for(int i = 0; paths_cmd[i] != NULL; i++)
		printf("%s\n", paths_cmd[i]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe my_pipe;
	int i;
	
	i = 0;
	
	if(!check_env(envp))
		exit_error("Error\nMissing environnement !\n");
	//printf("test");
	if (argc != 5)
		exit_error("Error\nNot enought arguments !\n");
	my_pipe.infile = open(argv[1], O_RDONLY);
	if (my_pipe.infile < 0)
		exit_error("Error\nError with intfile !\n");
	my_pipe.outfile = open(argv[argc -1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	//printf("d = %d\n", my_pipe.outfile);
	if (my_pipe.outfile < 0)
	{
		//close(my_pipe.infile);
		exit_error("Error\nWError with outfile !\n");
	}
	if (pipe(my_pipe.tube) < 0)
		exit_error("Error\nPipe failed !\n");
	my_pipe.paths = get_path(envp);
	my_pipe.paths_cmd = ft_split(my_pipe.paths, ':');
	my_pipe.pid_1 = fork();
	//printf("%d\n", my_pipe.pid_1);
	if (my_pipe.pid_1 == 0)
		first_child_process(my_pipe, argv, envp);
	// printf("path --> %s\n", my_pipe.paths);
	// dipslay_cmd(my_pipe.paths_cmd);
	my_pipe.pid_2 = fork();
	if (my_pipe.pid_2 == 0)
		second_child_process(my_pipe, argv, envp);
	close(my_pipe.tube[0]);
	close(my_pipe.tube[1]);
	waitpid(my_pipe.pid_1, NULL, 0);
	waitpid(my_pipe.pid_2, NULL, 0);
	free(my_pipe.paths);
	free_parent_process(&my_pipe);
	return (0);
}

// input = input_file "/bin/ls" "ls" output_file

// try access("/bin/ls", F_OK | X_OK);
// si ok return; execve;
// si pasok try access(path[0] + / + "ls", F_OK | X_OK);
// si pasok try access(path[1] + / + "ls", F_OK | X_OK);
// ....
// si pasok; "COMMAND NOT FOUND";