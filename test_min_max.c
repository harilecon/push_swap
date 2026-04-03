/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 07:41:46 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:35:25 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare(int i, char *str, int signe, int len)
{
	if (len == 10)
	{
		if (signe == 1)
			if (ft_strncmp(str + i, "2147483647", 11) <= 0)
				return (1);
		if (signe == -1)
			if (ft_strncmp(str + i, "2147483648", 11) <= 0)
				return (1);
	}
	return (0);
}

static int	min_max(char *str)
{
	int	i;
	int	signe;
	int	len;
	int	comp;

	signe = 1;
	i = 0;
	if (str[0] == '-')
	{
		signe = -1;
		i++;
	}
	if (str[0] == '+')
		i++;
	while (str[i] == '0')
		i++;
	len = ft_strlen(str + i);
	if (len < 10)
		return (1);
	if (len == 10)
	{
		comp = compare(i, str, signe, len);
		return (comp);
	}
	return (0);
}

char	**table_check_min_max(char **str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i])
	{
		if (!min_max(str[i]))
			return (str);
		i++;
	}
	return (NULL);
}
