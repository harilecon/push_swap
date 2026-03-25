/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:52:20 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/24 23:17:21 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_liste **b, t_bunch **bunch_mark)
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
	(*bunch_mark)->rrb++;
}

void	rrr(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	(*bunch_mark)->rrr++;
	(*bunch_mark)->rra--;
	(*bunch_mark)->rrb--;
	rra(a, bunch_mark);
	rrb(b, bunch_mark);
}

void	pa(t_liste **a, t_liste **b, t_bunch **bunch_mark)
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
	(*bunch_mark)->pa++;
}

void	pb(t_liste **a, t_liste **b, t_bunch **bunch_mark)
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
	(*bunch_mark)->pb++;
}
