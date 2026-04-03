/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:47:29 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:30:06 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	front_move(unsigned int pos, t_data **a, t_data **b,
		t_bench **bench_mark)
{
	unsigned int	i;

	i = 1;
	while (i < pos)
	{
		ra(a, bench_mark);
		i++;
	}
	if (i == pos)
	{
		pb(a, b, bench_mark);
	}
}

static void	back_move(unsigned int pos, t_data **a, t_data **b,
		t_bench **bench_mark)
{
	unsigned int	i;

	i = stack_size(*a);
	while (i >= pos)
	{
		rra(a, bench_mark);
		i--;
	}
	pb(a, b, bench_mark);
}

void	five_elements(t_data **stack, t_bench **bench_mark, double disorder)
{
	unsigned int	pos;
	unsigned int	size;
	t_data			*b;

	b = NULL;
	if (disorder == 0)
		return ;
	size = 5;
	while (size > 3)
	{
		pos = low_index(*stack);
		if (pos <= size / 2 + 1)
			front_move(pos, stack, &b, bench_mark);
		else if (pos > size / 2 + 1)
			back_move(pos, stack, &b, bench_mark);
		size--;
	}
	if (size == 3)
	{
		three_elements(stack, bench_mark, disorder);
		pa(stack, &b, bench_mark);
		pa(stack, &b, bench_mark);
	}
}
