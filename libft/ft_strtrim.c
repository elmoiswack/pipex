/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:16:36 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 15:58:22 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ckbegin(char const *s1, char const *set);
static int		ckend(char const *s1, char const *set);
static char		*rip(int i);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		begin;
	int		end;
	char	*ptr;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	begin = ckbegin(s1, set);
	end = ckend(s1, set) + 1;
	i = 0;
	if ((end - begin + 1) < 1)
		return (rip(i));
	ptr = (char *) malloc(end - begin + 1);
	if (!ptr)
		return (NULL);
	while (begin < end)
	{
		ptr[i] = s1[begin];
		i++;
		begin++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	ckbegin(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int	ckend(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static char	*rip(int i)
{
	char	*ptr;

	ptr = malloc(1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	return (ptr);
}
