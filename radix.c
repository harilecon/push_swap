/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 22:30:49 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 12:53:40 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(t_liste	**stack)
{
	int		j;
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

unsigned int	max_bits(t_liste *stack)
{
	unsigned int	bits;
	unsigned int	max;
	t_liste			*tmp;

	if (!stack)
		return (0);
	tmp = stack;
	bits = 0;
	max = stack->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((bits < 32) && ((max >> bits) != 0))
		bits++;
	return (bits);
}

int	check_order(t_liste *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	first(t_liste **a, t_liste **b, int j)
{
	unsigned int	i;
	unsigned int	size_a;

	i = 0;
	size_a = stack_size(*a);
	while (i < size_a)
	{
		if ((((*a)->index >> j) & 1) == 0)
		{
			ft_printf("pb\n");
			pb(a, b);
		}
		else
		{
			ft_printf("ra\n");
			ra(a);
		}
		i++;
	}
}

void	radix(t_liste **stack)
{
	t_liste			*a;
	t_liste			*b;
	int				j;
	int				bits;

	indexation(stack);
	i = 0;
	a = *stack;
	b = NULL;
	bits = max_bits(a);
	if (!bits)
		return ;
	j = 0;
	while (j < bits)
	{
		first(&a, &b, j);
		while (b)
		{
			ft_printf("pa\n");
			pa(&a, &b);
		}
		j++;
	}
	*stack = a;
}
