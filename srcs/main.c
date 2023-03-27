/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:35:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/27 15:02:10 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../libft/libft.h"

void	filling_struct(char *argv[], char *envp[], t_mainstruct *main_struct)
{
	main_struct->paths = get_paths(envp);
	if (!main_struct->paths)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to get paths");
	}
	main_struct->command_path_1 = get_paths_acces(main_struct->paths, argv, 2);
	if (!main_struct->command_path_1)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to get access");
	}
	main_struct->command_path_2 = get_paths_acces(main_struct->paths, argv, 3);
	if (!main_struct->command_path_2)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to get access");
	}
	return ;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_mainstruct	*main_struct;

	main_struct = ft_calloc(1, sizeof(t_mainstruct));
	if (!main_struct)
		error_exit("Error\nAllocation of struct failed");
	argument_checks(argc, argv, main_struct);
	filling_struct(argv, envp, main_struct);
	main_struct->fd1 = open(argv[1], O_RDONLY);
	main_struct->fd2 = open(argv[4], O_WRONLY);
	if (main_struct->fd1 < 0 || main_struct->fd2 < 0)
	{
		free_struct(main_struct);
		error_exit("Error\nFailed to open fd's");
	}
	parent_process(main_struct, envp);
	free_struct(main_struct);
	exit(EXIT_SUCCESS);
}
