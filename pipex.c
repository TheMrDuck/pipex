/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:38:37 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/04 19:09:29 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
void first_child_function(int *pipe_fd, char ** av, char **envp)
{
	int file1;
	char *path;
	char **cmd;

	printf("FirstChild");
	file1 = open(av[1], O_RDONLY);
	dup2(file1, 0);
	dup2(pipe_fd[1], 1);
	cmd = ft_split(av[2], ' ');
	path = path_finder(envp, av[2]);
	execve(path, cmd, envp);
}
void second_child_function(int *pipe_fd, char ** av, char **envp)
{
	int file2;
	char *path;
	char **cmd;

	printf("second Child");
	file2 = open(av[4], O_WRONLY);
	dup2(file2, 1);
	dup2(pipe_fd[0], 0);
	cmd = ft_split(av[3], ' ');
	path = path_finder(envp, av[3]);
	execve(path, cmd, envp);
}
int main(int ac, char **av, char **envp)
{
	int	pipe_fd[2];
	int pid1;
	int pid2;

	if (ac != 5)
		print_error("ERROR\nNot enough arguments");
	pipe(pipe_fd);
	pid1 = fork();
	if (pid1 == 0)
		first_child_function(pipe_fd, av, envp);
	pid2 = fork();
	if (pid2 == 0)
		second_child_function(pipe_fd, av, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
}
