/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:23 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 15:01:50 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_liste **b)
{
	t_liste	*last;
	t_liste	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	first = *b;
	while (last->next)
		last = last->next;
	(*b) = (*b)->next;
	(*b)->previous = NULL;
	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	rr(t_liste **a, t_liste **b)
{
	ra(a);
	rb(b);
}

void	rra(t_liste **a)
{
	t_liste	*last;
	t_liste	*b_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	b_last = last->previous;
	b_last->next = NULL;
	last->next = *a;
	last->previous = NULL;
	(*a)->previous = last;
	*a = last;
}

t_liste	*create_liste(long i)
{
	t_liste	*node;

	node = malloc(sizeof(t_liste));
	if (!node)
		return (NULL);
	node->value = i;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

long	char_lo(char *str)
{
	int		signe;
	int		i;
	long	nb;

	signe = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-')
	{
		signe = -1;
		i = 1;
	}
	nb = 0;
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * signe);
}
