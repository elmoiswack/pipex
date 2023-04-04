/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:35:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/04 16:11:35 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>

void	child_process_1(char *argv[], char *envp[], int *pipes, t_struct *strct)
{
	int		fd;
	char	*command_path;

	close(pipes[0]);
	fd = open(argv[1], O_RDONLY, 0000644);
	if (fd < 0)
		error_fork(pipes, 0, 66, argv);
	if (dup2(fd, STDIN_FILENO) == -1)
		error_fork(pipes, fd, 1, argv);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		error_fork(pipes, fd, 1, argv);
	error_fork(pipes, fd, 0, argv);
	command_path = get_command_path(strct->paths, strct->command_1[0]);
	if (!command_path)
	{
		error_exec(strct->command_1[0]);
		error_fork(pipes, fd, 127, argv);
	}
	if (execve(command_path, strct->command_1, envp) == -1)
	{
		error_exec(strct->command_1[0]);
		free(command_path);
		error_fork(pipes, fd, 1, argv);
	}
}

void	child_process_2(char *argv[], char *envp[], int *pipes, t_struct *strct)
{
	int		fd;
	char	*command_path;

	close(pipes[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 000644);
	if (fd < 0)
		error_fork(pipes, 0, 73, argv);
	if (dup2(pipes[0], STDIN_FILENO) == -1)
		error_fork(pipes, fd, 1, argv);
	if (dup2(fd, STDOUT_FILENO) == -1)
		error_fork(pipes, fd, 1, argv);
	error_fork(pipes, fd, 0, argv);
	command_path = get_command_path(strct->paths, strct->command_2[0]);
	if (!command_path)
	{
		error_exec(strct->command_2[0]);
		error_fork(pipes, fd, 127, argv);
	}
	if (execve(command_path, strct->command_2, envp) == -1)
	{
		error_exec(strct->command_2[0]);
		free(command_path);
		error_fork(pipes, fd, 1, argv);
	}
}

void	ft_exit(int status, t_struct *strct)
{
	free_struct(strct);
	if (!WIFEXITED(status))
		exit(EXIT_FAILURE);
	exit(WEXITSTATUS(status));
}

void	pipe_exec(char *argv[], char *envp[], t_struct *strct)
{
	pid_t	child1;
	pid_t	child2;
	int		pipes[2];
	int		wait_status;

	if (pipe(pipes) == -1)
	{
		free_struct(strct);
		error_exit("Error\nFailed to pipe");
	}
	child1 = fork();
	if (child1 < 0)
		error_fork(pipes, 0, 1, argv);
	if (child1 == 0)
		child_process_1(argv, envp, pipes, strct);
	child2 = fork();
	if (child2 < 0)
		error_fork(pipes, 0, 1, argv);
	if (child2 == 0)
		child_process_2(argv, envp, pipes, strct);
	close(pipes[0]);
	close(pipes[1]);
	waitpid(child1, &wait_status, 0);
	waitpid(child2, &wait_status, 0);
	ft_exit(wait_status, strct);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_struct	*strct;

	strct = ft_calloc(1, sizeof(t_struct));
	if (!strct)
		error_exit("Error\nAllocation of struct failed");
	argument_checks(argc, argv, envp, strct);
	pipe_exec(argv, envp, strct);
}
