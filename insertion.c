/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:51:17 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/19 15:45:51 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
				printf("ra\n");
				ra(&a);
				i++;
			}
		printf("pb\n");
		pb(&a, &b);
	}
	while (b)
	{
		printf("pa\n");
		pa(&a, &b);
	}
	*stack = a;
	//printf_stack(a, "la value de a = ");
}
