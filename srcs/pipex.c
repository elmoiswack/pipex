/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:35:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:37 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_mainstruct	*main_struct;

	argument_checks(argc);
	main_struct = ft_calloc(1, sizeof(t_mainstruct));
	if (!main_struct)
		error_exit("Error\nAllocation of struct failed");
	main_struct->paths = get_paths(envp);
	main_struct->command_path_1 = get_paths_acces(main_struct->paths, argv, 2);
	if (!main_struct->command_path_1)
	{
		free_2d_array(main_struct->paths);
		error_exit("Error\nFailed to get access");
	}
	printf("\n str = %s\n", main_struct->command_path_1);
	free(main_struct->command_path_1);
	main_struct->command_path_2 = get_paths_acces(main_struct->paths, argv, 3);
	if (!main_struct->command_path_2)
	{
		free_2d_array(main_struct->paths);
		error_exit("Error\nFailed to get access");
	}
	printf("\n str = %s\n", main_struct->command_path_2);
	free(main_struct->command_path_2);
	return (0);
}



//execve("/bin/cat", ("cat", "-e"), envp);