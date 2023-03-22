/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:14:49 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:09 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_string(va_list ptr, int len)
{
	char	*str;
	int		j;

	str = va_arg(ptr, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	if (str[0] == '\0')
		return (len);
	j = 0;
	while (str[j] != '\0')
	{
		write(1, &str[j], 1);
		j++;
		len++;
	}
	return (len);
}
