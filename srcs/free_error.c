/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:57:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/02 23:15:39 by dhussain         ###   ########.fr       */
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

void	free_struct(t_mainstruct *mainstruct)
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
	write(1, "pipex: ", 7);
	write(1, arg, ft_strlen(arg));
	write(1, ": command not found", 19);
	write(1, "\n", 1);
}

void	error_fork(int *pipes, t_mainstruct *main_struct, int numb)
{
	free_struct(main_struct);
	if (pipes[0] > 0)
		close(pipes[0]);
	if (pipes[1] > 0)
		close(pipes[1]);
	if (numb == 0)
		exit(1);
	if (numb == 1)
		exit(127);
}
