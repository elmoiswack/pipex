/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:52:09 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/06 11:53:42 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	if ((dst == (void *)0) && (src == (void *)0))
		return (NULL);
	i = 0;
	j = 0;
	while (i < n)
	{
		temp[j] = temp2[i];
		i++;
		j++;
	}
	return (dst);
}
