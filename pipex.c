/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aswedan <aswedan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:38:37 by aswedan           #+#    #+#             */
/*   Updated: 2025/02/17 17:25:46 by aswedan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	first_child_function(int *pipe_fd, char **av, char **envp)
{
	int		file1;
	char	*path;
	char	**cmd;

	file1 = open(av[1], O_RDONLY);
	dup2(file1, 0);
	dup2(pipe_fd[1], 1);
	close(file1);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd = ft_split(av[2], ' ');
	if (access(av[2], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = path_finder(envp, cmd[0]);
	if (!path)
		path = ft_strdup(" ");
	if (execve(path, cmd, envp) == -1)
	{
		write(2, "ERROR\nCMD1", ft_strlen("ERROR\nCMD1"));
		free_2d(cmd);
		free(path);
		exit(1);
	}
}

void	second_child_function(int *pipe_fd, char **av, char **envp)
{
	int		file2;
	char	*path;
	char	**cmd;

	file2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(file2, 1);
	dup2(pipe_fd[0], 0);
	close(file2);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	cmd = ft_split(av[3], ' ');
	if (access(av[3], X_OK) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = path_finder(envp, cmd[0]);
	if (!path)
		path = ft_strdup(" ");
	if (execve(path, cmd, envp) == -1)
	{
		write(2, "ERROR\nCMD2", ft_strlen("ERROR\nCMD2"));
		free_2d(cmd);
		free(path);
		exit(1);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	pipe_fd[2];
	int	pid1;
	int	pid2;

	if (ac != 5)
		print_error("ERROR\nNot enough arguments");
	pipe(pipe_fd);
	pid1 = fork();
	if (pid1 == -1)
		print_error("Your first child just died! Good job!\n");
	if (pid1 == 0)
		first_child_function(pipe_fd, av, envp);
	pid2 = fork();
	if (pid2 == -1)
		print_error("Your second child just died! Good job!\n");
	if (pid2 == 0)
		second_child_function(pipe_fd, av, envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
