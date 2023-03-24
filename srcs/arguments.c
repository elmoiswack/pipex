/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:15 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/24 10:10:19 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	into_struct(char *argv[], t_mainstruct *mainstruct)
{
	mainstruct->command_1 = ft_calloc(ft_strlen(argv[2]), sizeof(char));
	if (!mainstruct->command_1)
		return (-1);
	ft_strlcpy(mainstruct->command_1, argv[2], ft_strlen(argv[2]));
	mainstruct->command_2 = ft_calloc(ft_strlen(argv[3]), sizeof(char));
	if (!mainstruct->command_2)
		return (-1);
	ft_strlcpy(mainstruct->command_2, argv[3], ft_strlen(argv[3]));
	return (1);
}

int	argument_checks(int argc, char *argv[], t_mainstruct *mainstruct)
{
	if (argc < 5)
		error_exit("Error\nToo few arguments");
	if (argc > 5)
		error_exit("Error\nToo many arguments");
	if (into_struct(argv, mainstruct) == -1)
	{
		free_struct(mainstruct);
		error_exit("Error\nAllocation of commands in struct failed");
	}
	return (1);
}
