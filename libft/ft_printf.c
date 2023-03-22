/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:29:15 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 12:20:56 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_check2(const char *string, int i, int len);

int	ft_printf(const char *string, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, string);
	while (string[i] != '\0')
	{	
		while (string[i] == '%' && string[i + 1])
		{
			len = ft_printf_check(string, i, ptr, len);
			i = i + 2;
			if (string[i] == '\0')
			{
				va_end(ptr);
				return (len);
			}
		}
		len = ft_printf_check2(string, i, len);
		i++;
	}
	va_end(ptr);
	return (len);
}

static int	ft_printf_check2(const char *string, int i, int len)
{
	if (string[i] != '%')
	{
		write(1, &string[i], 1);
		len++;
	}
	return (len);
}

int	ft_printf_check(const char *string, int i, va_list ptr, int len)
{
	if (string[i + 1] == 'c')
		return (ft_printf_char(ptr, len));
	else if (string[i + 1] == 's')
		return (ft_printf_string(ptr, len));
	else if (string[i + 1] == 'p')
		return (ft_printf_pointer(ptr, len));
	else if ((string[i + 1] == 'i') || (string[i + 1] == 'd'))
		return (ft_printf_int(ptr, len));
	else if (string[i + 1] == 'u')
		return (ft_printf_unsigndec(ptr, len));
	else if (string[i + 1] == 'x')
		return (ft_printf_hexalower(ptr, len));
	else if (string[i + 1] == 'X')
		return (ft_printf_hexaupper(ptr, len));
	else if (string[i + 1] == '%')
	{
		write(1, "%%", 1);
		return (len + 1);
	}
	return (0);
}
