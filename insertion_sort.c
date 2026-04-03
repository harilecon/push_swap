/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:51:17 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:33:43 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_a(t_data **a, t_data **b, t_bench **bench_mark)
{
	unsigned int	index_low;
	unsigned int	i;

	while (*a)
	{
		index_low = low_index(*a);
		i = 0;
		if (index_low <= stack_size(*a) / 2)
		{
			while (i < index_low - 1)
			{
				ra(a, bench_mark);
				i++;
			}
		}
		else
		{
			while (stack_size(*a) - index_low + 1)
			{
				rra(a, bench_mark);
				index_low++;
			}
		}
		pb(a, b, bench_mark);
	}
}

void	insertion(t_data **stack, t_bench **bench_mark)
{
	t_data	*a;
	t_data	*b;
	double	disorder;

	disorder = compute_disorder(*stack);
	(*bench_mark)->complexity = "O(n^2)";
	if (disorder == 0)
		return ;
	b = NULL;
	a = *stack;
	if (a)
		for_a(&a, &b, bench_mark);
	while (b)
		pa(&a, &b, bench_mark);
	*stack = a;
}
