/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:22:34 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/19 15:59:45 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	buble(t_liste	**stack)
{
	int	size;
	int	i;
	int	ra_move;
	t_liste	*a = *stack;
	t_liste	*b = NULL;
	i = 0;
	size = stack_size(*stack);

	ra_move = 0;

	//printf("ton stack est = ");
	// printf_stack(a);
	while (i < size - 1)
	{
			if (!(a)->next)
				return ;
			if ((a)->next->value > (a)->value)
			{
				sa(&a);
				printf("sa\n");
				// printf_stack(a);
			}

			if (i < size - 1)
			{
				ra_move++;
				ra(&a);
				printf("ra\n");
				// printf_stack(a);
			}
			if (ra_move == size - 1)
			{
				pb(&a, &b);
				printf("pb\n");
				ra_move = 0;
				size--;
				i = -1;
			}
		i++;
	}
	printf("pb\n");
	pb(&a, &b);
	*stack = b;
	size = stack_size(*stack);
	i = 0;
	while (i < size)
	{
		printf("pa\n");
		pa(&a, &b);
		i++;
	}
	//printf("\n\nfinallement\n");
	// printf_stack(a);
}
