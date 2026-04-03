/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:30:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:34:57 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_data **stack)
{
	int		j;
	int		value;
	t_data	*tmp;
	t_data	*tmp_02;

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

static unsigned int	max_bits(t_data *stack)
{
	unsigned int	bits;
	unsigned int	max;
	t_data			*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	bits = 0;
	max = stack->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((bits < 32) && ((max >> bits) != 0))
		bits++;
	return (bits);
}

static void	first(t_data **a, t_data **b, int j, t_bench **bench_mark)
{
	unsigned int	i;
	unsigned int	size_a;

	i = 0;
	size_a = stack_size(*a);
	while (i < size_a)
	{
		if ((((*a)->index >> j) & 1) == 0)
			pb(a, b, bench_mark);
		else
			ra(a, bench_mark);
		i++;
	}
}

void	radix(t_data **stack, t_bench **bench_mark)
{
	t_data	*a;
	t_data	*b;
	int		j;
	int		bits;

	(*bench_mark)->complexity = "O(nlog(n))";
	if (compute_disorder(*stack) == 0)
		return ;
	a = *stack;
	b = NULL;
	bits = max_bits(a);
	if (!bits)
		return ;
	j = 0;
	while (j < bits)
	{
		first(&a, &b, j, bench_mark);
		while (b)
			pa(&a, &b, bench_mark);
		j++;
	}
	*stack = a;
}
