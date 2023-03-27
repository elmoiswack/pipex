/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:05:23 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/27 16:17:13 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	child_process_1(int fd, t_mainstruct *main_struct, char *envp[], int *pipes)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(pipes[1], STDOUT_FILENO) == -1)
		return (-1);
	close(pipes[0]);
	close (fd);
	execve(main_struct->command_path_1, main_struct->command_1, envp);
	return (1);
}

int	child_process_2(int fd, t_mainstruct *main_struct, char *envp[], int *pipes)
{
	close(pipes[0]);
	close(pipes[1]);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (-1);
	if (dup2(main_struct->fd2, STDOUT_FILENO) == -1)
		return (-1);
	close (fd);
	execve(main_struct->command_path_2, main_struct->command_2, envp);
	return (1);
}

void	parent_process(t_mainstruct *main_struct, char *envp[])
{
	pid_t	child1;
	pid_t	child2;
	int		pipes[2];
	int		wait_status;

	pipe(pipes);
	child1 = fork();
	if (child1 < 0)
	{
		close(pipes[0]);
		close(pipes[1]);
		free_struct(main_struct);
		error_exit("Error\nChild process 1 failed to fork");	
	}
	if (child1 == 0)
		child_process_1(main_struct->fd1, main_struct, envp, pipes);
	child2 = fork();
	if (child2 < 0)
	{
		close(pipes[0]);
		close(pipes[1]);	
		free_struct(main_struct);
		error_exit("Error\nChild process 2 failed to fork");
	}
	if (child2 == 0)
		child_process_2(main_struct->fd2, main_struct, envp, pipes);
	close(pipes[0]);
	close(pipes[1]);
	waitpid(child1, &wait_status, 0);
	waitpid(child2, &wait_status, 0);
	return ;
}
