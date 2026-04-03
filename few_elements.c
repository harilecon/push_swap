/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:46:50 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:58 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_data **stack, t_bench **bench_mark)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		ra(stack, bench_mark);
	}
}

static void	heavy_move(t_data **a, t_data **b, t_bench **bench_mark)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = (*a)->value;
	nb1 = (*a)->next->value;
	nb2 = (*a)->next->next->value;
	if (nb0 < nb2 && nb0 < nb1 && nb1 > nb2)
	{
		pb(a, b, bench_mark);
		ra(a, bench_mark);
		pa(a, b, bench_mark);
	}
	else if (nb0 > nb2 && nb0 > nb1 && nb1 > nb2)
	{
		sa(a, bench_mark);
		rra(a, bench_mark);
	}
	else if (nb0 > nb2 && nb0 > nb1 && nb1 < nb2)
	{
		rra(a, bench_mark);
		rra(a, bench_mark);
	}
}

void	three_elements(t_data **stack, t_bench **bench_mark, double disorder)
{
	unsigned int	nb0;
	unsigned int	nb1;
	unsigned int	nb2;
	t_data			*a;
	t_data			*b;

	a = *stack;
	b = NULL;
	if (disorder == 0)
		return ;
	nb0 = (*stack)->index;
	nb1 = (*stack)->next->index;
	nb2 = (*stack)->next->next->index;
	if (nb0 < nb2 && nb0 > nb1 && nb1 < nb2)
	{
		sa(&a, bench_mark);
	}
	else if (nb0 > nb2 && nb0 < nb1 && nb1 > nb2)
	{
		rra(&a, bench_mark);
	}
	else
		heavy_move(&a, &b, bench_mark);
	*stack = a;
}
