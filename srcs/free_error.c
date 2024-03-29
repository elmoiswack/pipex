/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:57:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/04 16:07:18 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	error_exit(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_2d_array(char **array)
{
	int	y;

	y = 0;
	while (array[y])
	{
		free(array[y]);
		y++;
	}
	free(array);
}

void	free_struct(t_struct *mainstruct)
{
	if (mainstruct->paths)
		free_2d_array(mainstruct->paths);
	if (mainstruct->command_1)
		free_2d_array(mainstruct->command_1);
	if (mainstruct->command_2)
		free_2d_array(mainstruct->command_2);
	free(mainstruct);
}

void	error_exec(char *arg)
{
	write(STDERR_FILENO, "pipex: ", 7);
	write(STDERR_FILENO, arg, ft_strlen(arg));
	write(STDERR_FILENO, ": command not found\n", 20);
}

int	error_fork(int *pipes, int fd, int exit_numb, char *argv[])
{
	if (fd > 0)
		close(fd);
	if (pipes[0] > 0)
		close(pipes[0]);
	if (pipes[1] > 0)
		close(pipes[1]);
	if (exit_numb == 1)
		exit(1);
	if (exit_numb == 66)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		write(STDERR_FILENO, argv[1], ft_strlen(argv[1]));
		write(STDERR_FILENO, ": no such file or directory\n", 28);
		exit(66);
	}
	if (exit_numb == 73)
	{
		write(STDERR_FILENO, "pipex: ", 7);
		write(STDERR_FILENO, argv[4], ft_strlen(argv[4]));
		write(STDERR_FILENO, ": no such file or directory\n", 28);
		exit(73);
	}
	if (exit_numb == 127)
		exit(127);
	return (0);
}
