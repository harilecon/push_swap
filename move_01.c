/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:28:36 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 14:58:42 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_liste **a)
{
	t_liste	*first;
	t_liste	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->previous = second;
	first->next = second->next;
	second->next = first;
	second->previous = NULL;
	*a = second;
	if (first->next)
		first->next->previous = first;
}

void	sb(t_liste **b)
{
	t_liste	*first;
	t_liste	*second;

	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->previous = second;
	first->next = second->next;
	second->next = first;
	second->previous = NULL;
	*b = second;
	if (first->next)
		first->next->previous = first;
}

void	ss(t_liste **a, t_liste **b)
{
	sa(a);
	sb(b);
}

void	ra(t_liste **a)
{
	t_liste	*last;
	t_liste	*first;

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
