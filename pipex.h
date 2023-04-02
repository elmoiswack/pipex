/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:32:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/02 22:56:40 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_mainstruct {
	char	**paths;
	char	**command_1;
	char	**command_2;
	int		check_1;
	int		check_2;
}	t_mainstruct;

//free and error functions
void	error_exit(char *str);
void	free_2d_array(char **array);
void	free_struct(t_mainstruct *mainstruct);
void	error_exec(char *arg);
void	error_fork(int *pipes, t_mainstruct *main_struct, int numb);

//ARGUMENTS
//arguments.c
void	argument_checks(int argc, char *argv[], char *envp[], t_mainstruct *mainstruct);
int		into_struct(char *argv[], t_mainstruct *mainstruct, char *envp[]);
//paths_creation.c
char	**get_paths(char *envp[]);
char	*get_command_path(char **paths, char *command);


#endif