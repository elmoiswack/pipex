/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:15 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/05 17:44:34 by dhussain         ###   ########.fr       */
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

int	check_argv_str(char *argv[])
{
	int	index_x;
	int	index_y;
	int	count;

	index_y = 1;
	while (argv[index_y])
	{
		count = 0;
		index_x = 0;
		while (argv[index_y][index_x])
		{
			if (ft_isalpha(argv[index_y][index_x]) == 1)
				count++;
			index_x++;
		}
		if (count == 0)
			return (-1);
		index_y++;
	}
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
	if (check_argv_str(argv) == -1)
	{
		free(mainstruct);
		error_exit("Error\nInvalid arguments");
	}
}

void	check_access_files(char *argv[])
{
	if (access(argv[1], R_OK | X_OK) == -1)
	{
		ft_printf("pipex: %s: Permission denied\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (access(argv[4], R_OK | W_OK | X_OK) == -1)
	{
		ft_printf("pipex: %s: Permission denied\n", argv[4]);
		exit(EXIT_FAILURE);
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
	check_access_files(argv);
	if (into_struct(argv, mainstruct, envp) == -1)
	{
		free_struct(mainstruct);
		error_exit("Error\nAllocation of commands in struct failed");
	}
}
