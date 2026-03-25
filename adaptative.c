/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptative.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 05:54:41 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/25 06:29:24 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function compute_disorder(stack a):
// mistakes = 0
// total_pairs = 0
// 	for i from 0 to size(a)-1:
// 		for j from i+1 to size(a)-1:
// 			total_pairs += 1
// 			if a[i] > a[j]:
// 			mistakes += 1
// return mistakes

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
