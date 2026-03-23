/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:51:17 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 12:51:29 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_a(t_liste **a, t_liste **b)
{
	int		index_low;
	int		i;

	while (*a)
	{
		index_low = low_index(*a);
		i = 0;
		while (i < index_low - 1)
		{
			ft_printf("ra\n");
			ra(a);
			i++;
		}
		ft_printf("pb\n");
		pb(a, b);
	}
}

void	insertion(t_liste **stack)
{
	t_liste	*a;
	t_liste	*b;

	b = NULL;
	a = *stack;
	if (a)
		for_a(&a, &b);
	while (b)
	{
		ft_printf("pa\n");
		pa(&a, &b);
	}
	*stack = a;
}
