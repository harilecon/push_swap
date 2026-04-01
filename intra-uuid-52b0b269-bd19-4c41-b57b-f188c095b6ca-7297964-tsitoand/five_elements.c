/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:47:29 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/01 14:03:42 by tsitoand         ###   ########.fr       */
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

void	five_elements(t_liste **stack, t_bunch **bunch_mark)
{
	unsigned int	pos;
	unsigned int	size;
	t_liste			*a;
	t_liste			*b;

	a = *stack;
	b = NULL;
	size = 5;
	while (size > 3)
	{
		pos = low_index(a);
		if (pos <= size / 2 + 1)
			front_move(pos, &a, &b, bunch_mark);
		else if (pos > size / 2 + 1)
			back_move(pos, &a, &b, bunch_mark);
		size--;
	}
	if (size == 3)
	{
		three_elements(&a, bunch_mark);
		pa(&a, &b, bunch_mark);
		pa(&a, &b, bunch_mark);
	}
	stack = &a;
}
