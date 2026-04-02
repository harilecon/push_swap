/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:46:50 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/02 17:20:58 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elements(t_liste **stack, t_bunch **bunch_mark)
{
	if ((*stack)->value > (*stack)->next->value)
	{
		ra(stack, bunch_mark);
	}
}

static void	heavy_move(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	int	nb0;
	int	nb1;
	int	nb2;

	nb0 = (*a)->value;
	nb1 = (*a)->next->value;
	nb2 = (*a)->next->next->value;
	if (nb0 < nb2 && nb0 < nb1 && nb1 > nb2)
	{
		pb(a, b, bunch_mark);
		ra(a, bunch_mark);
		pa(a, b, bunch_mark);
	}
	else if (nb0 > nb2 && nb0 > nb1 && nb1 > nb2)
	{
		sa(a, bunch_mark);
		rra(a, bunch_mark);
	}
	else if (nb0 > nb2 && nb0 > nb1 && nb1 < nb2)
	{
		rra(a, bunch_mark);
		rra(a, bunch_mark);
	}
}

void	three_elements(t_liste **stack, t_bunch **bunch_mark, double disorder)
{
	unsigned int		nb0;
	unsigned int		nb1;
	unsigned int		nb2;
	t_liste				*a;
	t_liste				*b;

	a = *stack;
	b = NULL;
	if (disorder == 0)
		return ;
	nb0 = (*stack)->index;
	nb1 = (*stack)->next->index;
	nb2 = (*stack)->next->next->index;
	if (nb0 < nb2 && nb0 > nb1 && nb1 < nb2)
	{
		sa(&a, bunch_mark);
	}
	else if (nb0 > nb2 && nb0 < nb1 && nb1 > nb2)
	{
		rra(&a, bunch_mark);
	}
	else
		heavy_move(&a, &b, bunch_mark);
	*stack = a;
}
