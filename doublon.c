/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 12:55:00 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/30 15:00:12 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int	condition_positive(char **number, int i, int j)
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
		if (ft_strcmp(number[i], number[j]))
			return (1);
	}
	else
	{
		if (!ft_strcmp(number[i], number[j]))
		return (1);
	}
	return (0);
}


int check_doublon_pos(char **number)
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
			condition_positive(number, i, j);
			// if ((number[i][0] == '+') || (number[j][0] == '+'))
			// {
			// 	if ((number[i][0] == '+') && (number[j][0]) != '+')
			// 	{
			// 		if (!ft_strcmp(number[i] + 1, number[j]))
			// 			return (1);
			// 	}
			// 	else if ((number[i][0] != '+') && (number[j][0]) == '+')
			// 	{
			// 		if (!ft_strcmp(number[i], number[j] + 1))
			// 			return (1);
			// 	}
			// 	else
			// 	if (ft_strcmp(number[i + 1], number[j + 1]))
			// 		return (1);
			// }
			// else
			// {
			// 	if (!ft_strcmp(number[i], number[j]))
			// 	return (1);
			// }
			j++;
		}
		i++;
	}
	return (0);
}

int	condition_negavite(char **number, int i, int j)
{
	if ((number[i][0] == '-') && (number[j][0] == '-'))
	{
		if ((number[i][0] == '-') && (number[j][0]) != '-')
		{
			if (!ft_strcmp(number[i] + 1, number[j]))
				return (1);
		}
		else if ((number[i][0] != '-') && (number[j][0]) == '-')
		{
			if (!ft_strcmp(number[i], number[j] + 1))
				return (1);
		}
		else
		if (ft_strcmp(number[i + 1], number[j + 1]))
			return (1);
	}
	else
	{
		if (!ft_strcmp(number[i], number[j]))
		return (1);
	}
	return (0);
}

int check_doublon_neg(char **number)
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
			if (condition_negavite(number, i ,j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int check_doublon(char **number)
{
	if (check_doublon_neg(number) || check_doublon_pos(number))
		return(1);
	return (0);
}
