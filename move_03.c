/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:23 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 07:33:14 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*first;

	(*bunch_mark)->rb++;
	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	first = *b;
	while (last->next)
		last = last->next;
	(*b) = (*b)->next;
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	rr(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	(*bunch_mark)->rr++;
	(*bunch_mark)->ra--;
	(*bunch_mark)->rb--;
	ra(a, bunch_mark);
	rb(b, bunch_mark);
}

void	rra(t_liste **a, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*b_last;

	(*bunch_mark)->rra++;
	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	b_last = last->previous;
	b_last->next = NULL;
	last->next = *a;
	last->previous = NULL;
	(*a)->previous = last;
	*a = last;
}
