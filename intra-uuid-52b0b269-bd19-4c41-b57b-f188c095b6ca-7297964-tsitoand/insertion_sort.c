/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:51:17 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 11:16:47 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_a(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	int		index_low;
	int		i;

	while (*a)
	{
		index_low = low_index(*a);
		i = 0;
		while (i < index_low - 1)
		{
			ra(a, bunch_mark);
			i++;
		}
		pb(a, b, bunch_mark);
	}
}

void	insertion(t_liste **stack, t_bunch **bunch_mark)
{
	t_liste	*a;
	t_liste	*b;
	double	disorder;

	disorder = compute_disorder(*stack);
	if (disorder == 0)
		return ;
	(*bunch_mark)->complexity = "O(n^2)";
	b = NULL;
	a = *stack;
	if (a)
		for_a(&a, &b, bunch_mark);
	while (b)
		pa(&a, &b, bunch_mark);
	*stack = a;
}
