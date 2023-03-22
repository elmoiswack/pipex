/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:15:42 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/07 15:24:35 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	char	a;

	a = c;
	if (a >= '0' && a <= '9')
		return (1);
	if (a >= 'A' && a <= 'Z')
		return (1);
	if (a >= 'a' && a <= 'z')
		return (1);
	return (0);
}
