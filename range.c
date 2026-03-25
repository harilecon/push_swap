/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/25 05:06:34 by tsitoand         ###   ########.fr       */
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

int	chunck_size(t_liste **stack)
{
	int	size;

	size = stack_size(*stack);
	if (size < 10)
		return (1);
	if (size >= 10 && size <= 100)
		return (size / 10);
	return (size / 30);
}

static void	for_a(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	unsigned int	i;
	unsigned int	chunck;

	chunck = chunck_size(a);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= (i + 1) * chunck)
		{
			ft_printf("pb\n");
			pb(a, b, bunch_mark);
		}
		else
		{
			ft_printf("ra\n");
			ra(a, bunch_mark);
		}
		if (stack_size(*b) >= (i + 1) * chunck)
			i++;
	}
}

static void	for_b(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	unsigned int	high;
	unsigned int	nb_rb;

	nb_rb = 0;
	while (*b)
	{
		high = high_index(*b);
		while (nb_rb < high - 1)
		{
			ft_printf("rb\n");
			rb(b, bunch_mark);
			nb_rb++;
		}
		ft_printf("pa\n");
		pa(a, b, bunch_mark);
		while (nb_rb)
		{
			ft_printf("rrb\n");
			rrb(b, bunch_mark);
			nb_rb--;
		}
	}
}

void	range(t_liste	**stack, t_bunch **bunch_mark)
{
	t_liste			*a;
	t_liste			*b;

	indexation(stack);
	a = *stack;
	b = NULL;
	if (a)
		for_a(&a, &b, bunch_mark);
	if (b)
		for_b(&a, &b, bunch_mark);
	*stack = a;
}
