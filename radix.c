/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:30:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/20 06:03:19 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	greatest(t_liste	*stack)
{
	long	value;

	value = stack->value;
	while (stack)
	{
		if (stack->value > value)
		{
			value = stack->value;
		}
		stack = stack->next;
	}
	return (value);
}

int	*indexation(t_liste	*stack)
{
	int	*tab;
	int	i;
	int	j;
	int	size;
	long	value;
	t_liste	*tmp;
	t_liste	*tmp_02;

	i = 0;
	j = 0;
	tmp = stack;
	size = stack_size(stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tmp_02 = stack;
		j = 0;
		value = tmp->value;
		while (tmp_02)
		{
			if (value > tmp_02->value)
				j++;
			tmp_02 = tmp_02->next;
		}
		tab[i] = j;
		i++;
		tmp = tmp->next;
	}
	return (tab);
}
