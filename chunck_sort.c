/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:34 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunck_size(t_data **stack)
{
	int	size;

	size = stack_size(*stack);
	if (size < 10)
		return (1);
	if (size >= 10 && size <= 100)
		return (size / 10);
	return (size / 30);
}

static void	for_a(t_data **a, t_data **b, t_bench **bench_mark)
{
	unsigned int	i;
	unsigned int	chunck;

	chunck = chunck_size(a);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= (i + 1) * chunck)
			pb(a, b, bench_mark);
		else
			ra(a, bench_mark);
		if (stack_size(*b) >= (i + 1) * chunck)
			i++;
	}
}

static void	for_b(t_data **a, t_data **b, t_bench **bench_mark)
{
	unsigned int	high;
	unsigned int	nb_rb;

	while (*b)
	{
		nb_rb = 0;
		high = high_index(*b);
		if (high <= stack_size(*b) / 2)
		{
			while (nb_rb < high - 1)
			{
				rb(b, bench_mark);
				nb_rb++;
			}
		}
		else
		{
			while (nb_rb < (stack_size(*b) - high) + 1)
			{
				rrb(b, bench_mark);
				nb_rb++;
			}
		}
		pa(a, b, bench_mark);
	}
}

void	chunck(t_data **stack, t_bench **bench_mark)
{
	t_data	*a;
	t_data	*b;
	double	disorder;

	(*bench_mark)->complexity = "O(n√n)";
	disorder = compute_disorder(*stack);
	if (disorder == 0)
		return ;
	a = *stack;
	b = NULL;
	if (a)
		for_a(&a, &b, bench_mark);
	if (b)
		for_b(&a, &b, bench_mark);
	*stack = a;
}
