/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:14:46 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/24 12:11:04 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>

char	**trim_paths(char **paths)
{
	int		index_p;
	int		index_s;
	char	*str;

	str = malloc ((ft_strlen(paths[0]) - 5) * sizeof(char));
	if (!str)
		return (NULL);
	index_p = 5;
	index_s = 0;
	while (paths[0][index_p])
	{
		str[index_s] = paths[0][index_p];
		index_s++;
		index_p++;
	}
	str[index_s] = '\0';
	index_s = 0;
	while (str[index_s])
	{
		paths[0][index_s] = str[index_s];
		index_s++; 
	}
	while (paths[0][index_s])
	{
		paths[0][index_s] = '\0';
		index_s++;
	}
	free(str);
	return (paths);
}

char	**get_paths(char *envp[])
{
	int		index;
	char	*str;
	char	**paths;
	
	index = 0;
	str = malloc (6 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "PATH=", 6);
	while (envp[index])
	{
		if (ft_strncmp(envp[index], str, 5) == 0)
			break ;
		index++;
	}
	free(str);
	paths = ft_split(envp[index], ':');
	if (!paths)
		return (NULL);
	paths = trim_paths(paths);
	if (!paths)
		return (NULL);
	paths = put_slash_behind(paths);
	return (paths);
}

char	**put_slash_behind(char **paths)
{
	int		index;
	char	*temp;

	index = 0;
	while (paths[index])
	{
		temp = paths[index];
		free(paths[index]);
		paths[index] = ft_strjoin(temp, "/");
		if (!paths[index])
		{
			free(temp);
			return (NULL);
		}
		index++;
	}
	free(temp);
	return (paths);
}

char	*get_paths_acces(char **paths, char *argv[], int index_argv)
{
	int		index;
	int		index_x;
	char	**temp_argv;
	char	*str;

	index = 0;
	index_x = 0;
	temp_argv = NULL;
	while (argv[index_argv][index_x] && argv[index_argv][index_x] != ' ')
		index_x++;
	if (argv[index_argv][index_x] == ' ')
		temp_argv = ft_split(argv[index_argv], ' ');
	while (paths[index])
	{
		if (!temp_argv)
			str = ft_strjoin(paths[index], argv[index_argv]);
		else
			str = ft_strjoin(paths[index], temp_argv[0]);
		if (!str)
			return (NULL);
		if (access(str, F_OK) == 0)
		{
			if (temp_argv)
				free_2d_array(temp_argv);
			return (str);
		}
		free(str);
		index++;
	}
	if (temp_argv)
		free_2d_array(temp_argv);
	return (NULL);
}