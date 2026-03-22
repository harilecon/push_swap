/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/22 14:10:44 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include "push_swap.h"


int	chunck_size(t_liste **stack)
{
	int	size;

	size = stack_size(*stack);
	return (size / 10);
}


void	range(t_liste	**stack)
{
	t_liste	*a;
	t_liste	*b;
	int		i;
	int		j;
	int		nb_rb;
	int		size;
	int		chunck;
	unsigned int high;

	indexation(stack);
	chunck = chunck_size(stack);
	i = 0;
	a = *stack;
	size = stack_size(a);
	j = 0;
	b = NULL;
	while(a)
	{
		if (a->index <= (i + 1) * chunck)
		{
			printf("pb\n");
			pb(&a, &b);
		}
		else
		{
			printf("ra\n");
			ra(&a);
		}
			j++;
		if (stack_size(b) >= (i + 1) * chunck)
			i++;
	}

	nb_rb = 0;
	while (b)
	{
		high = high_index(b);
		while (nb_rb < high - 1)
		{
			printf("rb\n");
			rb(&b);
			nb_rb++;
		}
		printf("pa\n");
		pa(&a, &b);
		while (nb_rb)
		{
			printf("rrb\n");
			rrb(&b);
			nb_rb--;
		}

	}


//	printf ("tessteeeeee");
	// *stack = a;
	// printf_stack_index(a, "stack A = ");
	// printf_stack_index(b , "stack B = ");
}
