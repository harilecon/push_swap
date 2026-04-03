/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunck_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:17:35 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 04:31:52 by tsitoand         ###   ########.fr       */
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
		return (size / 20);
	return (size / 30);
}
static unsigned int up_search(t_liste **chunck, unsigned int max)
{
	unsigned int	i;
	t_liste			*tmp;

	tmp = *chunck;
	i = 0;
	while (tmp)
	{
		if (tmp->index < max)
		return i;
			tmp = tmp->next;
		i++;
	}
	return (i);
}

static unsigned int down_search(t_liste **chunck, unsigned int max)
{
	unsigned int	i;
	t_liste			*tmp;

	tmp = *chunck;
	i = 1;
	while (tmp->next)
		tmp = tmp->next;

	while (tmp)
	{
		if (tmp->index < max)
		return i;
			tmp = tmp->previous;
		i++;
	}
	return (i);
}



static void	for_a(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	unsigned int	i;
	unsigned int	chunck;
	unsigned int	up;
	unsigned int	down;
	unsigned int	k;

	chunck = chunck_size(a);

	i = 0;
	while (*a)
	{
		k = 0;
		up = up_search(a, (unsigned int)(i + 1) * chunck);
		down = down_search(a, (unsigned int)(i + 1) * chunck);
		if ((*a)->index <= (i + 1) * chunck)
			pb(a, b, bunch_mark);
		else
		{
			if (up <= down)
			{
				while (k < up)
				{
					ra(a, bunch_mark);
					k++;
				}
			}
			else if (up > down)
			{
				while (k < down)
				{
					rra(a, bunch_mark);
					k++;
				}
			}
		}
		if (stack_size(*b) >= (i + 1) * chunck)
			i++;
	}
}

static void	for_b(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	unsigned int	high;
	unsigned int	nb_rb;

	while (*b)
	{
		nb_rb = 0;
		high = high_index(*b);
		if (high <= stack_size(*b) / 2)
		{
			while (nb_rb < high - 1)
			{
				rb(b, bunch_mark);
				nb_rb++;
			}
		}
		else
		{
			while (nb_rb < (stack_size(*b) - high) + 1)
			{
				rrb(b, bunch_mark);
				nb_rb++;
			}
		}
		pa(a, b, bunch_mark);
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
