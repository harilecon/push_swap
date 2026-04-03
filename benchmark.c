/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 07:06:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:29:23 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialisation_bench_value(t_bench **bench_mark)
{
	(*bench_mark)->complexity = NULL;
	(*bench_mark)->strategy = NULL;
	(*bench_mark)->sa = 0;
	(*bench_mark)->sb = 0;
	(*bench_mark)->ss = 0;
	(*bench_mark)->ra = 0;
	(*bench_mark)->rb = 0;
	(*bench_mark)->rr = 0;
	(*bench_mark)->rra = 0;
	(*bench_mark)->rrb = 0;
	(*bench_mark)->rrr = 0;
	(*bench_mark)->pa = 0;
	(*bench_mark)->pb = 0;
}

void	bench(double disorder, t_bench *bench_mark)
{
	int	total;
	int	fd;

	fd = 2;
	total = bench_mark->sa + bench_mark->sb + bench_mark->ss + bench_mark->pa
		+ bench_mark->pb + bench_mark->ra + bench_mark->rb + bench_mark->rr
		+ bench_mark->rra + bench_mark->rrb + bench_mark->rrr;
	ft_printf_fd(fd, "[bench]		disorder: %f%%\n", disorder * 100);
	ft_printf_fd(fd, "[bench]		strategy: %s / %s\n", bench_mark->strategy,
		bench_mark->complexity);
	ft_printf_fd(fd, "[bench]		total_ops: %d\n", total);
	ft_printf_fd(fd, "[bench]		sa: %d	sb: %d	ss: %d	pa: %d	pb: %d\n",
		bench_mark->sa, bench_mark->sb, bench_mark->ss,
		bench_mark->pa, bench_mark->pb);
	ft_printf_fd(fd, "[bench]\t\tra: %d rb: %d \
rr: %d rra: %d rrb: %d rrr: %d\n",
		bench_mark->ra,
		bench_mark->rb, bench_mark->rr,
		bench_mark->rra, bench_mark->rrb,
		bench_mark->rrr);
}
