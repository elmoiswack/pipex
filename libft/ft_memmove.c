/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:14:16 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 12:19:10 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static void	*mem_cpy(unsigned char *tsrc, unsigned char *tdest,
				size_t i, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tdest;
	unsigned char	*tsrc;

	i = 0;
	tdest = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	if ((dst == (void *)0) && (src == (void *)0))
		return (NULL);
	if (len == 0)
		return (tdest);
	if (tsrc > tdest)
	{
		mem_cpy(tsrc, tdest, i, len);
		return (tdest);
	}
	else
	{
		i = len;
		while (i-- > 0)
			tdest[i] = tsrc[i];
		tdest[0] = tsrc[0];
	}
	return (tdest);
}

static void	*mem_cpy(unsigned char *tsrc, unsigned char *tdest,
			size_t i, size_t len)
{
	while (i < len)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (tdest);
}
