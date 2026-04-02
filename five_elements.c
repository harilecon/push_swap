/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:47:29 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/01 18:28:30 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	front_move(unsigned int pos, t_liste **a,
	t_liste **b, t_bunch **bunch_mark)
{
	unsigned int	i;

	i = 1;
	while (i < pos)
	{
		ra(a, bunch_mark);
		i++;
	}
	if (i == pos)
	{
		pb(a, b, bunch_mark);
	}
}

static void	back_move(unsigned int pos, t_liste **a, t_liste **b,
		t_bunch **bunch_mark)
{
	unsigned int	i;

	i = stack_size(*a);
	while (i >= pos)
	{
		rra(a, bunch_mark);
		i--;
	}
	pb(a, b, bunch_mark);
}

void	five_elements(t_liste **stack, t_bunch **bunch_mark, double disorder)
{
	unsigned int	pos;
	unsigned int	size;
	t_liste			*b;

	b = NULL;
	if (disorder == 0)
		return ;
	size = 5;
	while (size > 3)
	{
		pos = low_index(*stack);
		if (pos <= size / 2 + 1)
			front_move(pos, stack, &b, bunch_mark);
		else if (pos > size / 2 + 1)
			back_move(pos, stack, &b, bunch_mark);
		size--;
	}
	if (size == 3)
	{
		three_elements(stack, bunch_mark, disorder);
		pa(stack, &b, bunch_mark);
		pa(stack, &b, bunch_mark);
	}
}
