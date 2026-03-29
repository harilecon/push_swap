/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:22:34 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/29 08:05:50 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ra_mv(t_liste **a, t_bunch **bunch_mark)
{
	ra(a, bunch_mark);
	ft_printf("ra\n");
	return (1);
}

static void	loop(t_liste **a, t_liste **b, int size, int i, t_bunch **bunch_mark)
{
	int	ra_move;

	ra_move = 0;
	while (i < size - 1)
	{
		if (!(*a)->next)
			return ;
		if ((*a)->next->value > (*a)->value)
		{
			sa(a, bunch_mark);
			ft_printf("sa\n");
		}
		if (i < size - 1)
			ra_move = ra_move + ra_mv(a, bunch_mark);
		if (ra_move == size - 1)
		{
			pb(a, b, bunch_mark);
			ft_printf("pb\n");
			ra_move = 0;
			size--;
			i = -1;
		}
		i++;
	}
}

void	bubble(t_liste	**stack, t_bunch	**bunch_mark)
{
	int		size;
	int		i;
	t_liste	*a;
	t_liste	*b;

	if (compute_disorder(*stack) == 0)
		return ;
	(*bunch_mark)->complexity = "bubble";
	if (stack_size(*stack) == 2)
	{
		two_element(stack, bunch_mark);
		return ;
	}
	a = *stack;
	b = NULL;
	i = 0;
	size = stack_size(*stack);
	loop(&a, &b, size, i, bunch_mark);
	ft_printf("pb\n");
	pb(&a, &b, bunch_mark);
	*stack = b;
	size = stack_size(*stack);
	while (i < size)
	{
		ft_printf("pa\n");
		pa(&a, &b, bunch_mark);
		i++;
	}
	*stack = a;
}
