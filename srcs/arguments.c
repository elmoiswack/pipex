/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:15 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:57 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../libft/libft.h"

int	into_struct(char *argv[], t_struct *mainstruct, char *envp[])
{
	mainstruct->command_1 = ft_split(argv[2], ' ');
	if (!mainstruct->command_1)
		return (-1);
	mainstruct->command_2 = ft_split(argv[3], ' ');
	if (!mainstruct->command_2)
		return (-1);
	mainstruct->paths = get_paths(envp);
	if (!mainstruct->paths)
		return (-1);
	return (1);
}

void	check_argv(char *argv[], t_struct *mainstruct)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		if (argv[index][0] == '\0')
		{
			free(mainstruct);
			error_exit("Error\nInvalid arguments");
		}
		index++;
	}
}

void	argument_checks(int argc, char *argv[], char *envp[],
				t_struct *mainstruct)
{
	int	index;

	index = 0;
	if (argc < 5)
	{
		free(mainstruct);
		error_exit("Error\nToo few arguments");
	}
	if (argc > 5)
	{
		free(mainstruct);
		error_exit("Error\nToo many arguments");
	}
	check_argv(argv, mainstruct);
	if (into_struct(argv, mainstruct, envp) == -1)
	{
		free_struct(mainstruct);
		error_exit("Error\nAllocation of commands in struct failed");
	}
}
