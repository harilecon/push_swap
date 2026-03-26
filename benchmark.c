/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    benchmark.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:06:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 08:08:31 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	initialisation_bunch_value(t_bunch **bunch_mark)
{
	(*bunch_mark)->complexity = NULL;
	(*bunch_mark)->sa = 0;
	(*bunch_mark)->sb = 0;
	(*bunch_mark)->ss = 0;
	(*bunch_mark)->ra = 0;
	(*bunch_mark)->rb = 0;
	(*bunch_mark)->rr = 0;
	(*bunch_mark)->rra = 0;
	(*bunch_mark)->rrb = 0;
	(*bunch_mark)->rrr = 0;
	(*bunch_mark)->pa = 0;
	(*bunch_mark)->pb = 0;
}

void	bunch(t_bunch	*bunch_mark)
{

	int total = bunch_mark->sa + bunch_mark->sb + bunch_mark->ss + bunch_mark->pa + bunch_mark->pb + bunch_mark->ra + bunch_mark->rb + bunch_mark->rr + bunch_mark->rra + bunch_mark->rrb + bunch_mark->rrr;
	ft_printf("[bench]		disorder: \n");
	ft_printf("[bench]		strategy: %s\n", bunch_mark->complexity);
	ft_printf("[bench]		total_ops: %d\n", total);
	ft_printf("[bench]		sa: %d	sb: %d	ss: %d	pa: %d	pb: %d\n", bunch_mark->sa, bunch_mark->sb, bunch_mark->ss, bunch_mark->pa, bunch_mark->pb);
	ft_printf("[bench]		ra: %d	rb: %d	rr: %d	rra: %d	rrb: %d	rrr: %d\n", bunch_mark->ra, bunch_mark->rb, bunch_mark->rr,bunch_mark->rra, bunch_mark->rrb, bunch_mark->rrr);

}
