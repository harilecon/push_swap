/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:22:34 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 13:57:13 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buble(t_liste	**stack)
{
	int		size;
	int		i;
	int		ra_move;
	t_liste	*a;
	t_liste	*b;

	a = *stack;
	b = NULL;
	i = 0;
	size = stack_size(*stack);
	ra_move = 0;
	while (i < size - 1)
	{
		if (!(a)->next)
			return ;
		if ((a)->next->value > (a)->value)
		{
			sa(&a);
			ft_printf("sa\n");
		}
		if (i < size - 1)
		{
			ra_move++;
			ra(&a);
			ft_printf("ra\n");
		}
		if (ra_move == size - 1)
		{
			pb(&a, &b);
			ft_printf("pb\n");
			ra_move = 0;
			size--;
			i = -1;
		}
		i++;
	}
	ft_printf("pb\n");
	pb(&a, &b);
	*stack = b;
	size = stack_size(*stack);
	i = 0;
	while (i < size)
	{
		ft_printf("pa\n");
		pa(&a, &b);
		i++;
	}
	*stack = a;
}
