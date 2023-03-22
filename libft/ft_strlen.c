/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 16:50:02 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/06 12:22:06 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
