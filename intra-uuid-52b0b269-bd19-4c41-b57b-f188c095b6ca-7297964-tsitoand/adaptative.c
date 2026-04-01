/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:54:41 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/01 15:00:24 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_liste *stack)
{
	t_liste	*tmp;
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

static void	less_than_five(int size, t_liste **stack, t_bunch **bunch_mark)
{
	if (size == 2)
		two_elements(stack, bunch_mark);
	else if (size == 3)
	{
		three_elements(stack, bunch_mark);
		return ;
	}
	else if (size == 5)
		five_elements(stack, bunch_mark);
}

void	choose_your_destiny(t_liste	**stack, t_bunch **bunch_mark)
{
	double			disorder;
	unsigned int	size;

	(*bunch_mark)->strategy = "adaptive";
	size = stack_size(*stack);
	disorder = compute_disorder(*stack);
	if (disorder < 0.2)
		(*bunch_mark)->complexity = "O(n^2)";
	else if ((0.2 <= disorder) && (disorder < 0.5))
		(*bunch_mark)->complexity = "O(n√n)";
	else
		(*bunch_mark)->complexity = "O(nlog(n))";
	if ((size <= 5) && (size != 1) && (size != 4))
		less_than_five(size, stack, bunch_mark);
	else
	{
		if (disorder < 0.2)
			insertion(stack, bunch_mark);
		else if ((0.2 <= disorder) && (disorder < 0.5))
			range(stack, bunch_mark);
		else
			radix(stack, bunch_mark);
	}
}
