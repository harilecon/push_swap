/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:54:41 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:02 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_data *stack)
{
	t_data	*tmp;
	double	mistakes;
	double	total_pairs;

	if (!stack || !stack->next)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			total_pairs++;
			if (stack->value > tmp->value)
				mistakes++;
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (mistakes / total_pairs);
}

static void	less_than_five(int size, t_data **stack, t_bench **bench_mark)
{
	double	disorder;

	disorder = compute_disorder(*stack);
	if (size == 2)
		two_elements(stack, bench_mark);
	else if (size == 3)
	{
		three_elements(stack, bench_mark, disorder);
		return ;
	}
	else if (size == 5)
		five_elements(stack, bench_mark, disorder);
}

static void	condition(double disorder, t_data **stack, t_bench **bench_mark)
{
	if (disorder < 0.2)
		insertion(stack, bench_mark);
	else if ((0.2 <= disorder) && (disorder < 0.5))
		chunck(stack, bench_mark);
	else
		radix(stack, bench_mark);
}

void	choose_your_destiny(t_data **stack, t_bench **bench_mark)
{
	double			disorder;
	unsigned int	size;

	(*bench_mark)->strategy = "adaptive";
	if (!stack[0])
	{
		(*bench_mark)->complexity = "none";
		return ;
	}
	size = stack_size(*stack);
	disorder = compute_disorder(*stack);
	if (disorder < 0.2)
		(*bench_mark)->complexity = "O(n^2)";
	else if ((0.2 <= disorder) && (disorder < 0.5))
		(*bench_mark)->complexity = "O(n√n)";
	else
		(*bench_mark)->complexity = "O(nlog(n))";
	if ((size <= 5) && (size != 1) && (size != 4))
		less_than_five(size, stack, bench_mark);
	else
	{
		condition(disorder, stack, bench_mark);
	}
}
