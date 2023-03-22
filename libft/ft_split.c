/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:15:43 by dhussain          #+#    #+#             */
/*   Updated: 2022/10/19 14:03:06 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wcount(char const *s, char c);
static int		wlenght(char const *s, char c, int i);
static char		**ree(char **arr, int j);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = 0;
	arr = (char **) ft_calloc(wcount(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (j < wcount(s, c))
	{
		while (s[i] == c)
			i++;
		temp = wlenght(s, c, i);
		arr[j] = ft_substr(s, i, temp);
		if (!arr[j])
			return (ree(arr, j));
		j++;
		i += temp;
	}
	return (arr);
}

int	wcount(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (i == (int)ft_strlen(s))
			return (count);
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

int	wlenght(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ree(char **arr, int j)
{
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
	return (0);
}
