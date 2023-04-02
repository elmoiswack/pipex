/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:35:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/02 23:20:44 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>

int		child_process_1(char *argv[], char *envp[], int *pipes, t_mainstruct *main_struct)
{
	int		fd;
	char	*command_path;

	close(pipes[0]);
	fd = open(argv[1], O_RDONLY, 420);
	if (fd < 0)
		exit(1);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(1);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		exit(1);
	command_path = get_command_path(main_struct->paths, main_struct->command_1[0]);
	if (!command_path)
		return (-1);
	if (execve(command_path, main_struct->command_1, envp) == -1)
	{
		free(command_path);
		return (-1);
	}
	close(fd);
	close(pipes[1]);
	free(command_path);
	return (1);
}

int		child_process_2(char *argv[], char *envp[], int *pipes, t_mainstruct *main_struct)
{
	int		fd;
	char	*command_path;

	close(pipes[1]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 420);
	if (fd < 0)
		exit(1);
	if (dup2(pipes[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(1);
	command_path = get_command_path(main_struct->paths, main_struct->command_2[0]);
	if (!command_path)
		return (-1);
	if (execve(command_path, main_struct->command_2, envp) == -1)
	{
		free(command_path);
		return (-1);
	}
	close(fd);
	close(pipes[0]);
	free(command_path);
	return (1);
}

void	pipe_exec(char *argv[], char *envp[], t_mainstruct *main_struct)
{
	pid_t	child1;
	pid_t	child2;
	int		pipes[2];
	int		wait_status;

	if (pipe(pipes) == -1)
		error_exit("Error\nFailed to pipe");
	child1 = fork();
	if (child1 < 0)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to fork!");
	}
	if (child1 == 0)
	{
		if (child_process_1(argv, envp, pipes, main_struct) == -1)
		{
			error_exec(main_struct->command_1[0]);
		}
	}
	child2 = fork();
	if (child2 < 0)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to fork!");
	}
	if (child2 == 0)
	{
		if (child_process_2(argv, envp, pipes, main_struct) == -1)
		{
			error_exec(main_struct->command_2[0]);
			free_struct(main_struct);
			exit(127);
		}
	}
	waitpid(child1, &wait_status, 0);
	waitpid(child1, &wait_status, 0);
	close(pipes[0]);
	close(pipes[1]);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_mainstruct	*main_struct;

	main_struct = ft_calloc(1, sizeof(t_mainstruct));
	if (!main_struct)
		error_exit("Error\nAllocation of struct failed");
	argument_checks(argc, argv, envp, main_struct);
	pipe_exec(argv, envp, main_struct);
	free_struct(main_struct);
	exit(EXIT_SUCCESS);
}
