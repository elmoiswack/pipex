/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhussain <dhussain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:15 by dhussain          #+#    #+#             */
/*   Updated: 2023/03/22 12:16:15 by dhussain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	argument_checks(int argc)
{
	if (argc < 5)
		error_exit("Error\nToo few arguments");
	if (argc > 5)
		error_exit("Error\nToo many arguments");
	return (1);
}
