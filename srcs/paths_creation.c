/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:14:46 by dhussain          #+#    #+#             */
/*   Updated: 2023/04/02 22:42:46 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include "../libft/libft.h"

char	*trim_paths(char *str_path)
{
	char	*str;

	str = ft_substr(str_path, 5, ft_strlen(str_path) - 5);
	free(str_path);
	return (str);
}

char	**put_slash_behind(char **paths)
{
	int		index;
	char	*temp;

	index = 0;
	while (paths[index])
	{
		temp = ft_calloc(ft_strlen(paths[index]) + 1, sizeof(char));
		if (!temp)
			return (NULL);
		ft_strlcpy(temp, paths[index], ft_strlen(paths[index]) + 1);
		free(paths[index]);
		paths[index] = ft_strjoin(temp, "/");
		free(temp);
		if (!paths[index])
			return (NULL);
		index++;
	}
	return (paths);
}

char	**get_paths(char *envp[])
{
	int		index;
	char	**paths;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			break ;
		index++;
	}
	if (envp[index] == NULL)
		return (NULL);
	paths = ft_split(envp[index], ':');
	if (!paths)
		return (NULL);
	paths[0] = trim_paths(paths[0]);
	if (!paths)
		return (NULL);
	paths = put_slash_behind(paths);
	return (paths);
}

char	*get_command_path(char **paths, char *command)
{
	int		index;
	char	*temp;

	index = 0;
	while (paths[index])
	{
		temp = ft_strjoin(paths[index], command);
		if (!temp)
			return (NULL);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
		free(temp);
		index++;
	}
	return (NULL);
}
