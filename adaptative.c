/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:54:41 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/29 08:03:42 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

double	compute_disorder(t_liste *stack)
{
	t_liste	*tmp;
	double	mistakes;
	double total_pairs;

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

void	choose_your_destiny(t_liste	**stack, t_bunch **bunch_mark)
{
	double disorder;

	(*bunch_mark)->strategy = "adaptive";
	disorder = compute_disorder(*stack);
	if (disorder < 0.2)
	{
		insertion(stack, bunch_mark);
	}
	else if ((0.2 <= disorder) && (disorder < 0.5))
	{
		range(stack, bunch_mark);
	}
	else
	{
		radix(stack, bunch_mark);
	}
}
