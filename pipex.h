/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:32:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/24 12:07:50 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"

typedef struct s_mainstruct {
	char	**paths;
	char	*command_1;
	char	*command_2;
	char	*command_path_1;
	char	*command_path_2;
	int		fd1;
	int		fd2;
}	t_mainstruct;

//free and error functions
void	error_exit(char *str);
void	free_2d_array(char **array);
void	free_struct(t_mainstruct *mainstruct);

//ARGUMENTS
//arguments.c
int		argument_checks(int argc, char *argv[], t_mainstruct *mainstruct);
int		into_struct(char *argv[], t_mainstruct *mainstruct);
//paths_creation.c
char	**get_paths(char *envp[]);
char	**put_slash_behind(char **paths);
char	*get_paths_acces(char **paths, char *argv[], int index_argv);

//pipex.c
void	pipe_function(int fd1, int fd2, t_mainstruct *main_struct);

#endif