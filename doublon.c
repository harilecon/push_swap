/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:55:00 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/27 14:01:27 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int check_doublon(char **number)
{
	int		i;
	int		j;

	if (!number)
		return (-1);
	i = 0;
	while (number[i])
	{
		j = i + 1;
		while (number[j])
		{
			if (!ft_strcmp(number[i], number[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
