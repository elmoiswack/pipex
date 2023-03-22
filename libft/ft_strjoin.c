/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:26:10 by dhussain          #+#    #+#             */
/*   Updated: 2022/12/23 12:56:54 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
