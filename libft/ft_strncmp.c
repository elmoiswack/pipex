/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:55:53 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/21 11:49:30 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *src, const char *str, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)str;
	while (((ptr1[i] != '\0') || (ptr2[i] != '\0')) && (i < n))
	{
		if (ptr1[i] != ptr2[i])
		{
			diff = ptr1[i] - ptr2[i];
			if (diff < 0)
				return (diff);
			if (diff > 0)
				return (diff);
		}
		i++;
	}
	return (0);
}
