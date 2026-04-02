/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:55:00 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 08:06:17 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	condition_neg(char **number, int i, int j)
{
	int	k;
	int	l;

	k = 1;
	l = 1;
	if ((number[i][0] == '-') && (number[j][0] == '-'))
	{
		while (number[i][k] == '0')
			k++;
		while (number[j][l] == '0')
			l++;
		if (!ft_strcmp(number[i] + k, number[j] + l))
			return (1);
	}
	return (0);
}

static int	condition_pos(char **number, int i, int j)
{
	if ((number[i][0] == '+') || (number[j][0] == '+'))
	{
		if ((number[i][0] == '+') && (number[j][0]) != '+')
		{
			if (!ft_strcmp(number[i] + 1, number[j]))
				return (1);
		}
		else if ((number[i][0] != '+') && (number[j][0]) == '+')
		{
			if (!ft_strcmp(number[i], number[j] + 1))
				return (1);
		}
		else
			if (!ft_strcmp(number[i], number[j]))
				return (1);
	}
	else
	{
		if (!ft_strcmp(number[i], number[j]))
			return (1);
	}
	return (0);
}

int	check_doublon_pos(char **number)
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
			if (condition_pos(number, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doublon_neg(char **number)
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
			if (condition_neg(number, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_doublon(char **number)
{
	if (check_doublon_neg(number) || check_doublon_pos(number))
		return (1);
	return (0);
}
