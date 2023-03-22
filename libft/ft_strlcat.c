/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:07:52 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 14:05:40 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	cpyl(char *dest, const char *src, size_t j, size_t dstsize);

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	sum;

	j = 0;
	i = 0;
	if (!dest && dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	sum = i + j;
	if (dstsize < j)
	{
		sum = i + dstsize;
		return (sum);
	}
	if (dstsize > j)
		j = cpyl(dest, src, j, dstsize);
	return (sum);
}

static int	cpyl(char *dest, const char *src, size_t j, size_t dstsize)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && j < (dstsize - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (j);
}
