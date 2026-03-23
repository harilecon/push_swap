/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:51:17 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 13:35:58 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void insertion(t_liste **stack)
{
	t_liste	*a;
	t_liste	*b;

	int index_low;
	int	i;
	int size;

	i = 0;

	b = NULL;
	a = *stack;

	while (a)
	{
		index_low = low_index(a);
		size = stack_size(a);
		i = 0;

			while (i < index_low - 1)
			{
				ft_printf("ra\n");
				ra(&a);
				i++;
			}
		ft_printf("pb\n");
		pb(&a, &b);
	}
	while (b)
	{
		ft_printf("pa\n");
		pa(&a, &b);
	}
	*stack = a;
}
