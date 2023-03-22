/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:34:52 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/11 16:52:18 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chck1(void);
static char	*chck2(int i);
static char	*mathishard(int n, int count, int i);
static char	*switcheroo(int x, char *ptr);

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		x;
	int		count;

	i = 0;
	x = 0;
	count = 0;
	if (n == 0)
		return (chck1());
	if (n == -2147483648)
		return (chck2(i));
	if (n < 0)
	{
		n = n * -1;
		i++;
		x++;
	}
	ptr = mathishard(n, count, i);
	if (ptr != NULL)
		ptr = switcheroo(x, ptr);
	return (ptr);
}

static char	*chck1(void)
{
	char	*ptr;

	ptr = malloc(2);
	if (!ptr)
		return (NULL);
	ptr[0] = '0';
	ptr[1] = '\0';
	return (ptr);
}

static char	*chck2(int i)
{
	char	*begin;
	char	*ptr;

	begin = "-2147483648\0";
	ptr = malloc(ft_strlen(begin) + 1);
	if (!ptr)
		return (NULL);
	while (begin[i] != '\0')
	{
		ptr[i] = begin[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*mathishard(int n, int count, int i)
{
	int		nee;
	char	*ptr;

	nee = n;
	while (!(n < 1))
	{
		n = n / 10;
		count++;
	}
	ptr = ft_calloc((count + 2), 1);
	if (!ptr)
		return (NULL);
	if (i == 1)
		ptr[0] = '-';
	while (!(nee < 1))
	{
		ptr[i] = (nee % 10) + 48;
		nee = nee / 10;
		i++;
	}
	return (ptr);
}

static char	*switcheroo(int x, char *ptr)
{
	int		y;
	char	temp;
	char	*begin;
	char	*end;

	begin = &ptr[x];
	y = ft_strlen(ptr) - 1;
	end = &ptr[y];
	while (end > begin)
	{
		temp = *end;
		*end = *begin;
		*begin = temp;
		end--;
		begin++;
	}
	return (ptr);
}
