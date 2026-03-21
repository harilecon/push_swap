/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/21 13:58:36 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


int	chunck_size(t_liste **stack)
{
	int	size;

	size = stack_size(*stack);
	return (size / 6);
}


void	range(t_liste	**stack)
{
	t_liste	*a;
	t_liste	*b;
	int		i;
	int		j;
	int		k;
	int		chunck;

	indexation(stack);
	chunck = chunck_size(stack);
	i = 0;
	j = 0;
	k = 0;
	a = *stack;
	b = NULL;
	while(k )
	{
		k = 0;
		while (a)
		{
			if ((a->index >= i * chunck) && (a->index <= (i + 1) * chunck))
				pb(&a, &b);
			else
				ra(&a);
			k++;
		}
		i++;
	}
	*stack = a;
}
