/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 07:45:28 by haranivo          #+#    #+#             */
/*   Updated: 2026/03/27 01:14:30 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] == '-' || str[0] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**all_number(int argc, char **argv)
{
	char	**number;
	char	**str;
	int		loc;
	int		i;
	int		k;

	number = malloc(sizeof(char *) * argc);
	if (!number)
		return (NULL);
	loc = where_flag(argc, argv);
	str = argument(argc, argv);
	i = 0;
	while (str[i])
	{
		k = 0;
		if (i != loc && ft_is_number(str[i]))
			return (NULL);
		number[k] = str[i];
		k++;
		i++;
	}
	number[k] = NULL;
	free_tab(str);
	return (number);
}

char	**check_doublon(int argc, char **argv)
{
	char	**number;
	int		i;
	int		j;

	number = all_number(argc, argv);
	i = 0;
	while (number[i])
	{
		j = i + 1;
		while (number[j])
		{
			if (ft_strcmp(number[i], number[i + j]))
				return (NULL);
			j++;
		}
		i++;
	}
	return (number);
}
