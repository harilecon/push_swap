/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:30:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/20 13:33:40 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	greatest(t_liste	*stack)
{
	long	value;

	value = stack->value;
	while (stack)
	{
		if (stack->value > value)
		{
			value = stack->value;
		}
		stack = stack->next;
	}
	return (value);
}

void	indexation(t_liste	**stack)
{
	int	j;
	long	value;
	t_liste	*tmp;
	t_liste	*tmp_02;

	j = 0;
	tmp = *stack;
	 while (tmp)
	{
		tmp_02 = *stack;
		j = 0;
		value = tmp->value;
		while (tmp_02)
		{
			if (value > tmp_02->value)
				j++;
			tmp_02 = tmp_02->next;
		}
		tmp->index = j;
		tmp = tmp->next;
	}
}

int	max_bits(t_liste *stack)
{
	int	bits;
	int	max;
	t_liste	*tmp;

	tmp = stack;
	bits = 0;
	max = stack->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void radix(t_liste **stack)
{
	t_liste	*b;
	int		i;
	int		j;
	int		size;
	int		max;

	b = NULL;
	i = 0;
	max = max_bits(*stack);

	while (i < max)
	{
		j = 0;
		size = stack_size(*stack);

		while (j < size)
		{
			if ((((*stack)->index >> i) & 1) == 0)
			pb(stack, &b);
			else
			ra(stack);
			j++;
		}

		while (b)
		pa(stack, &b);

		i++;
	}
	printf_stack(*stack , "a le stack a apres manipulaion");
}


/*
void radix(t_liste **stack)
{
	t_liste	*a;
	t_liste	*b;
	int		i;
	int		j;
	int		size;
	int		max;


	a = *stack;
	b = NULL;
	i = 0;
	max = max_bits(*stack);
	while(i < max)
	{
		j = 0;
		size = stack_size(a);
		while(i < size)
		{
			if (((a->index >> i) & 1) == 0)
				pb(&a, &b);
			else
				ra(&a);
			j++;
		}

		while (b)
		{
			pa(&a, &b);
		}
		i++;
	}
}
*/
/*
void radix(t_liste **a)
{
	t_liste	*b;
	int		i;
	int		j;
	int		size;
	int		max;

	b = NULL;
	i = 0;
	max = max_bits(*a);

	while (i < max)
	{
		j = 0;
		size = stack_size(*a);

		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, &b);
			else
				ra(a);
			j++;
		}

		while (b)
			pa(a, &b);

		i++;
	}
}

void radix(t_liste **stack)
{
	t_liste	*b;
	int		i;
	int		j;
	int		size;
	int		max;

	b = NULL;
	i = 0;
	max = max_bits(*stack);

	while (i < max)
	{
		j = 0;
		size = stack_size(*stack);

		while (j < size)
		{
			if ((((*stack)->index >> i) & 1) == 0)
				pb(stack, &b);
			else
				ra(stack);
			j++;
		}

		while (b)
			pa(stack, &b);

		i++;
	}
}
*/
