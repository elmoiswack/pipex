/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:15:47 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 11:22:25 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*end_file(char *sen, char *read_ptr, int read_count, int j)
{
	int	i;

	i = 0;
	read_ptr[read_count] = '\0';
	sen = new_malloc(sen);
	if (!sen)
		return (NULL);
	while ((i < read_count) && (read_ptr[i] != '\n'))
	{
		sen[j] = read_ptr[i];
		i++;
		j++;
	}
	if (read_ptr[i] == '\n')
		return (finish_sen(sen, read_ptr, i, j));
	sen[j] = '\0';
	read_ptr[0] = '\0';
	return (sen);
}

char	*finish_sen(char *sen, char *read_ptr, int i, int j)
{
	sen = new_malloc(sen);
	if (!sen)
		return (NULL);
	sen[j] = read_ptr[i];
	i++;
	j++;
	sen[j] = '\0';
	j = 0;
	while (read_ptr[i])
	{
		read_ptr[j] = read_ptr[i];
		i++;
		j++;
	}
	read_ptr[j] = '\0';
	return (sen);
}

int	copy_cat(char *sen, char *read_ptr, int j)
{
	int	i;

	i = 0;
	while ((read_ptr[i]) && (read_ptr[i] != '\n'))
	{
		sen[j] = read_ptr[i];
		i++;
		j++;
	}
	sen[j] = '\0';
	return (j);
}

char	*make_sen(char *read_ptr, char *sen, int fd)
{
	int	i;
	int	j;
	int	read_count;

	i = 0;
	j = 0;
	while (1)
	{
		j = copy_cat(sen, read_ptr, j);
		while ((read_ptr[i]) && (read_ptr[i] != '\n'))
			i++;
		if (read_ptr[i] == '\n')
			return (finish_sen(sen, read_ptr, i, j));
		read_count = read(fd, read_ptr, BUFFER_SIZE);
		if (read_count_check(sen, read_ptr, read_count) == -1)
			return (NULL);
		if (read_count_check(sen, read_ptr, read_count) == 1)
			return (end_file(sen, read_ptr, read_count, j));
		sen = new_malloc(sen);
		if (!sen)
			return (NULL);
		i = 0;
	}
}

char	*get_next_line(int fd)
{
	static char		read_ptr[BUFFER_SIZE + 1];
	char			*sen;
	int				i;

	i = 0;
	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE < 1)
		return (NULL);
	sen = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!sen)
		return (NULL);
	while (i < (BUFFER_SIZE + 1))
	{
		sen[i] = '\0';
		i++;
	}
	return (make_sen(read_ptr, sen, fd));
}
