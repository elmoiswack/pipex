/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:32:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/22 15:52:36 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

typedef struct s_mainstruct {
	char	**paths;
	char	*command_path_1;
	char	*command_path_2;
}	t_mainstruct;

//free and error functions
void	error_exit(char *str);
void	free_2d_array(char **array);

//ARGUMENTS
//arguments.c
int		argument_checks(int argc);


char	**get_paths(char *envp[]);
char	**put_slash_behind(char **paths);
char	*get_paths_acces(char **paths, char *argv[], int index_argv);

#endif