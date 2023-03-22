/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:17:42 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/06 12:19:54 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	j = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ptr1[i] != ptr2[j])
			return (ptr1[i] - ptr2[j]);
		i++;
		j++;
	}
	return (0);
}
