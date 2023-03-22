/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:16:03 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 13:59:55 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*ptr;

	i = 0;
	a = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = a;
		i++;
	}
}
