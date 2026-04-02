/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:23 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 18:18:45 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rf(t_liste **b)
{
	t_liste	*last;
	t_liste	*first;

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

void	rb(t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*first;

	ft_printf_fd(1, "rb\n");
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
	ft_printf_fd(1, "rr\n");
	(*bunch_mark)->rr++;
	rf(a);
	rf(b);
}

void	rra(t_liste **a, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*a_last;

	ft_printf_fd(1, "rra\n");
	(*bunch_mark)->rra++;
	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	a_last = last->previous;
	a_last->next = NULL;
	last->next = *a;
	last->previous = NULL;
	(*a)->previous = last;
	*a = last;
}

void	ra(t_liste **a, t_bunch **bunch_mark)
{
	t_liste	*last;
	t_liste	*first;

	ft_printf_fd(1, "ra\n");
	(*bunch_mark)->ra++;
	if ((!a) || (!*a) || (!(*a)->next))
		return ;
	last = *a;
	first = *a;
	while (last->next)
		last = last->next;
	(*a) = (*a)->next;
	(*a)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}
