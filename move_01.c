/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:28:36 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 18:17:10 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ss_f(t_liste **a)
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

void	sa(t_liste **a, t_bunch **bunch_mark)
{
	t_liste	*first;
	t_liste	*second;

	(*bunch_mark)->sa++;
	ft_printf_fd(1, "sa\n");
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

void	sb(t_liste **b, t_bunch **bunch_mark)
{
	t_liste	*first;
	t_liste	*second;

	ft_printf_fd(1, "sb\n");
	(*bunch_mark)->sb++;
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

void	ss(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	ft_printf_fd(1, "ss\n");
	(*bunch_mark)->ss++;
	ss_f(a);
	ss_f(b);
}
