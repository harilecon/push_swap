/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:28:36 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:34:28 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ss_f(t_data **a)
{
	t_data	*first;
	t_data	*second;

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

void	sa(t_data **a, t_bench **bench_mark)
{
	t_data	*first;
	t_data	*second;

	(*bench_mark)->sa++;
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

void	sb(t_data **b, t_bench **bench_mark)
{
	t_data	*first;
	t_data	*second;

	ft_printf_fd(1, "sb\n");
	(*bench_mark)->sb++;
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

void	ss(t_data **a, t_data **b, t_bench **bench_mark)
{
	ft_printf_fd(1, "ss\n");
	(*bench_mark)->ss++;
	ss_f(a);
	ss_f(b);
}
