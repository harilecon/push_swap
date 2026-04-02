/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 20:19:56 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			pb(a, b, bunch_mark);
		else
			ra(a, bunch_mark);
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
			rb(b, bunch_mark);
			nb_rb++;
		}
		pa(a, b, bunch_mark);
		while (nb_rb)
		{
			rrb(b, bunch_mark);
			nb_rb--;
		}
	}
}

void	chunck(t_liste	**stack, t_bunch **bunch_mark)
{
	t_liste			*a;
	t_liste			*b;
	double			disorder;

	(*bunch_mark)->complexity = "O(n√n)";
	disorder = compute_disorder(*stack);
	if (disorder == 0)
		return ;
	a = *stack;
	b = NULL;
	if (a)
		for_a(&a, &b, bunch_mark);
	if (b)
		for_b(&a, &b, bunch_mark);
	*stack = a;
}
