/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:23 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:34:43 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rf(t_data **b)
{
	t_data	*last;
	t_data	*first;

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

void	rb(t_data **b, t_bench **bench_mark)
{
	t_data	*last;
	t_data	*first;

	ft_printf_fd(1, "rb\n");
	(*bench_mark)->rb++;
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

void	rr(t_data **a, t_data **b, t_bench **bench_mark)
{
	ft_printf_fd(1, "rr\n");
	(*bench_mark)->rr++;
	rf(a);
	rf(b);
}

void	rra(t_data **a, t_bench **bench_mark)
{
	t_data	*last;
	t_data	*a_last;

	ft_printf_fd(1, "rra\n");
	(*bench_mark)->rra++;
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

void	ra(t_data **a, t_bench **bench_mark)
{
	t_data	*last;
	t_data	*first;

	ft_printf_fd(1, "ra\n");
	(*bench_mark)->ra++;
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
