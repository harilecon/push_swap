/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:52:20 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 14:05:15 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_liste **b)
{
	t_liste	*last;
	t_liste	*b_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	b_last = last->previous;
	b_last->next = NULL;
	last->next = *b;
	last->previous = NULL;
	(*b)->previous = last;
	*b = last;
}

void	rrr(t_liste **a, t_liste **b)
{
	rra(a);
	rrb(b);
}

void	pa(t_liste **a, t_liste **b)
{
	t_liste	*tmp;

	if (!a || !b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;
	tmp->next = *a;
	tmp->previous = NULL;
	if (*a)
		(*a)->previous = tmp;
	*a = tmp;
}

void	pb(t_liste **a, t_liste **b)
{
	t_liste	*tmp;

	if (!b || !a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->previous = NULL;
	tmp->next = *b;
	tmp->previous = NULL;
	if (*b)
		(*b)->previous = tmp;
	*b = tmp;
}
