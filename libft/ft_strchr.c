/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:20:12 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/07 15:08:02 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;
	char	a;

	i = 0;
	ptr = (char *)str;
	a = c;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == a)
			return (&ptr[i]);
		i++;
	}
	if (ptr[i] == '\0' && a == '\0')
		return (&ptr[i]);
	return (0);
}
