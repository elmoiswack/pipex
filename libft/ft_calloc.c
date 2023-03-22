/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:49:04 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/10 11:18:30 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;
	char	a;
	size_t	total;

	total = count * size;
	ptr = (void *) malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	a = '\0';
	while (total > 0)
	{
		ptr[i] = a;
		i++;
		total--;
	}
	return ((void *)ptr);
}
