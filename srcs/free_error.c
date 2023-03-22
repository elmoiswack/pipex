/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:57:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/22 12:16:07 by dhussain         ###   ########.fr       */
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