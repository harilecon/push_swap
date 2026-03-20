/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:30:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/20 07:19:25 by tsitoand         ###   ########.fr       */
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

void	indexation(t_liste	**stack)
{
	int	j;
	long	value;
	t_liste	*tmp;
	t_liste	*tmp_02;

	j = 0;
	tmp = *stack;
	 while (tmp)
	{
		tmp_02 = *stack;
		j = 0;
		value = tmp->value;
		while (tmp_02)
		{
			if (value > tmp_02->value)
				j++;
			tmp_02 = tmp_02->next;
		}
		tmp->index = j;
		tmp = tmp->next;
	}
}

int	max_bits(t_liste *stack)
{
	int	bits;
	int	max;
	t_liste	*tmp;

	tmp = stack;
	bits = 0;
	max = stack->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
