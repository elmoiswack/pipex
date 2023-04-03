/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:32:00 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/03 14:18:23 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_struct {
	char	**paths;
	char	**command_1;
	char	**command_2;
}	t_struct;

//free and error functions
void	error_exit(char *str);
void	free_2d_array(char **array);
void	free_struct(t_struct *strct);
void	error_exec(char *arg);
int		error_fork(int *pipes, int fd, int numb);

//ARGUMENTS
//arguments.c
void	argument_checks(int argc, char *argv[], char *envp[],
			t_struct *strct);
int		into_struct(char *argv[], t_struct *strct, char *envp[]);
//paths_creation.c
char	**get_paths(char *envp[]);
char	*get_command_path(char **paths, char *command);

#endif