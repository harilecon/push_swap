/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:52:20 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 11:20:39 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrr_f(t_liste **b)
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

void	rrb(t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*b_last;

	ft_printf("rrb\n");
	(*bunch_mark)->rrb++;
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

void	rrr(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	ft_printf("rrr\n");
	(*bunch_mark)->rrr++;
	rrr_f(b);
	rrr_f(a);
}

void	pa(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*tmp;

	ft_printf("pa\n");
	(*bunch_mark)->pa++;
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

void	pb(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*tmp;

	ft_printf("pb\n");
	(*bunch_mark)->pb++;
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
