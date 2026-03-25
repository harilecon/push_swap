/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:23 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/25 04:53:47 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_liste **b, t_bunch **bunch_mark)
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
	(*bunch_mark)->rb++;
}

void	rr(t_liste **a, t_liste **b, t_bunch **bunch_mark)
{
	(*bunch_mark)->rr++;
	(*bunch_mark)->ra--;
	(*bunch_mark)->rb--;
	ra(a, bunch_mark);
	rb(b, bunch_mark);
}

void	rra(t_liste **a, t_bunch **bunch_mark)
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
	(*bunch_mark)->rra++;
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
