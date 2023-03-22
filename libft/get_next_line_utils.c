/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 08:47:10 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 12:18:34 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strlength(char *str)
{
	int	i;

	i = 0;
	while ((str[i]) && (str[i] != '\n'))
		i++;
	return (i);
}

char	*gnl_cpy(char *dest, char *src)
{
	int	i;
	int	j;

	j = strlength(src);
	i = 0;
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*new_malloc(char *str)
{
	int		i;
	int		j;
	char	*temp;

	i = strlength(str);
	temp = malloc((i + BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (free(str), NULL);
	j = i;
	i += BUFFER_SIZE;
	temp = gnl_cpy(temp, str);
	while (j < i)
	{
		temp[j] = '\0';
		j++;
	}
	free(str);
	return (temp);
}

int	read_count_check(char *sen, char *read_ptr, int read_count)
{
	if (read_count < BUFFER_SIZE)
	{
		if (read_count == -1 || (read_count == 0 && *sen == '\0'))
		{
			read_ptr[0] = '\0';
			return (free(sen), -1);
		}
		return (1);
	}
	return (0);
}
