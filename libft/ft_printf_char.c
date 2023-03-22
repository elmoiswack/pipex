/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:14:08 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/14 11:27:27 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_char(va_list ptr, int len)
{
	char	c;

	c = va_arg(ptr, int);
	write(1, &c, 1);
	len++;
	return (len);
}
