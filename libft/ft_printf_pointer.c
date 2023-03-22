/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:15:48 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/23 11:57:55 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(unsigned long long j, char *tempstr,
				int len, char *str);

int	ft_printf_pointer(va_list ptr, int len)
{
	void				*tempptr;
	char				*tempstr;
	int					i;
	unsigned long long	j;
	char				*str;

	write(1, "0x", 2);
	i = 0;
	tempptr = va_arg(ptr, void *);
	if (!tempptr)
	{
		write(1, "0", 1);
		return (len + 3);
	}
	j = (unsigned long long)tempptr;
	tempstr = ft_mallocaaa(j);
	if (!tempstr)
		return ((char) NULL);
	str = "0123456789abcdef";
	return (convert(j, tempstr, len, str));
}

static int	convert(unsigned long long j, char *tempstr,
			int len, char *str)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (j != 0)
	{
		temp = j % 16;
		j = j / 16;
		tempstr[i] = str[temp];
		i++;
	}
	i -= 1;
	while (i >= 0)
	{
		write(1, &tempstr[i], 1);
		i--;
		len++;
	}
	free(tempstr);
	return (len + 2);
}
