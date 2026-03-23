/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 14:56:46 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunck_size(t_liste **stack)
{
	int	size;

	size = stack_size(*stack);
	return (size / 10);
}

static void	for_a(t_liste **a, t_liste **b)
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
			pb(a, b);
		}
		else
		{
			ft_printf("ra\n");
			ra(a);
		}
		if (stack_size(*b) >= (i + 1) * chunck)
			i++;
	}
}

static void	for_b(t_liste **a, t_liste **b)
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
			rb(b);
			nb_rb++;
		}
		ft_printf("pa\n");
		pa(a, b);
		while (nb_rb)
		{
			ft_printf("rrb\n");
			rrb(b);
			nb_rb--;
		}
	}
}

void	range(t_liste	**stack)
{
	t_liste			*a;
	t_liste			*b;
	int				size;

	indexation(stack);
	a = *stack;
	size = stack_size(a);
	b = NULL;
	if (a)
		for_a(&a, &b);
	if (b)
		for_b(&a, &b);
	*stack = a;
}
