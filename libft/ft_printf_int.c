/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:16:28 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:18 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftwrite(unsigned long j, char *str, int len);

int	ft_printf_int(va_list ptr, int len)
{
	long			i;
	unsigned long	j;
	char			*str;

	i = va_arg(ptr, signed int);
	if (i < 0)
		len++;
	j = intcheck(i);
	if (j == 0)
		return (len + 1);
	str = ft_mallocaaa(j);
	if (!str)
		return ((char) NULL);
	len = ftwrite(j, str, len);
	free(str);
	return (len);
}

static int	ftwrite(unsigned long j, char *str, int len)
{
	int	temp;

	temp = 0;
	while (j != 0)
	{
		str[temp] = (j % 10) + 48;
		j = j / 10;
		temp++;
	}
	temp--;
	while (temp >= 0)
	{
		write(1, &str[temp], 1);
		temp--;
		len++;
	}
	return (len);
}
