/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dhussain <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:04:42 by dhussain      #+#    #+#                 */
/*   Updated: 2022/10/11 15:08:05 by dhussain      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nee;
	char	temparr[15];

	i = 0;
	n = check(n, fd);
	if (n == 0)
		return ;
	else
	{
		while (!(n < 1))
		{
			nee = (n % 10) + 48;
			temparr[i] = nee;
			n = n / 10;
			i++;
		}
		i = i - 1;
		while (!(i < 0))
		{
			write(fd, &temparr[i], 1);
			i--;
		}
	}
}

static int	check(int n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
		return (n);
	}
	if (n < 10)
	{
		temp = n + 48;
		write(fd, &temp, 1);
		return (0);
	}
	return (n);
}
