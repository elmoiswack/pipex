/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:57:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/24 12:09:31 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>

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
	return ;
}

void	free_struct(t_mainstruct *mainstruct)
{
	if (mainstruct->fd1 != 0)
		close(mainstruct->fd1);
	if (mainstruct->fd2 != 0)
		close(mainstruct->fd2);
	if (mainstruct->paths)
		free_2d_array(mainstruct->paths);
	if (mainstruct->command_1)
		free(mainstruct->command_1);
	if (mainstruct->command_2)
		free(mainstruct->command_2);
	if (mainstruct->command_path_1)
		free(mainstruct->command_path_1);
	if (mainstruct->command_path_2)
		free(mainstruct->command_path_2);
	free(mainstruct);
	return ;
}