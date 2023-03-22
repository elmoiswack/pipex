/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexaupper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:18:43 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:22 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftconvert(unsigned int j, char *tempstr, char *str, int len);

int	ft_printf_hexaupper(va_list ptr, int len)
{
	char				tempstr[15];
	unsigned int		j;
	char				*str;

	j = va_arg(ptr, unsigned int);
	if (j == 0)
	{
		write(1, "0", 1);
		len++;
	}
	str = "0123456789ABCDEF";
	len = ftconvert(j, tempstr, str, len);
	return (len);
}

static int	ftconvert(unsigned int j, char *tempstr, char *str, int len)
{
	int				i;
	unsigned int	temp;

	i = 0;
	while (j != 0)
	{
		temp = j % 16;
		j = j / 16;
		tempstr[i] = str[temp];
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &tempstr[i], 1);
		i--;
		len++;
	}
	return (len);
}
