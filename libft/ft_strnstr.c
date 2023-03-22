/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:02:01 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 14:07:53 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static char	*ftfinish(int i, int j, const char *haystack, const char *ptr)
{
	i = i - j;
	ptr = &haystack[i];
	return ((char *)ptr);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		chck;
	const char	*ptr;

	i = 0;
	j = 0;
	if ((needle[j] == '\0') || (needle == haystack))
		return ((char *)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		chck = i;
		while ((haystack[i] == needle[j]) && (needle[j]) && (haystack[i]))
		{
			i++;
			j++;
			if ((needle[j] == '\0') && (i <= len))
				return (ftfinish(i, j, haystack, ptr));
		}
		i = chck;
		i++;
		j = 0;
	}
	return (0);
}
