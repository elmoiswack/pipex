/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 12:05:36 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/06 14:13:58 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_calc(const char *str, int i);

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	sum;

	i = 0;
	sum = 0;
	count = 0;
	while ((str[i] == ' ') || (str[i] == '\n')
		|| (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		count += 1;
		i++;
	}
	if (str[i] == '+')
		i++;
	sum = ft_calc(str, i);
	if (count == 1)
		sum = sum * -1;
	return (sum);
}

static int	ft_calc(const char *str, int i)
{
	int	nb;
	int	sum;

	sum = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (sum);
		nb = str[i] - 48;
		sum = sum + nb;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			sum = sum * 10;
		i++;
	}
	return (sum);
}
