/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:09:15 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/06 12:11:01 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	a;

	i = 0;
	ptr = (void *)s;
	a = c;
	while (i < n)
	{
		if (ptr[i] == a)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
