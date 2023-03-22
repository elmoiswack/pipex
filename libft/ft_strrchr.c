/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:13:40 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 15:44:32 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	char		cookies;
	const char	*ptr;

	cookies = (char)c;
	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] == '\0' && cookies == '\0')
		return ((char *)str + i);
	while ((i >= 0))
	{
		if (str[i] == cookies)
		{
			ptr = &str[i];
			return ((char *)ptr);
		}
		i--;
	}
	return (0);
}
