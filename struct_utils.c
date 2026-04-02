/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:53:06 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/01 14:54:17 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_liste **lst, t_liste *new_value)
{
	t_liste	*tmp;

	if (!lst || !new_value)
		return ;
	if (!*lst)
	{
		*lst = new_value;
		new_value->next = NULL;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_value;
	new_value->previous = tmp;
	new_value->next = NULL;
}

unsigned int	stack_size(t_liste	*liste)
{
	unsigned int	i;

	i = 0;
	while (liste)
	{
		liste = liste->next;
		i++;
	}
	return (i);
}

int	high_index(t_liste	*liste)
{
	t_liste	*tmp;
	int		high;
	int		i;

	if (!liste)
		return (0);
	i = 0;
	tmp = liste;
	high = liste->value;
	while (tmp)
	{
		if (tmp->value > high)
			high = tmp->value;
		tmp = tmp->next;
	}
	while (liste)
	{
		i++;
		if (high == liste->value)
			return (i);
		liste = liste->next;
	}
	return (i);
}

static int	low_value(t_liste *liste)
{
	int			low;
	t_liste		*tmp;

	tmp = liste;
	low = liste->value;
	while (tmp)
	{
		if (tmp->value < low)
			low = tmp->value;
		tmp = tmp->next;
	}
	return (low);
}

unsigned int	low_index(t_liste *liste)
{
	int	low;
	int	i;

	if (!liste)
		return (0);
	i = 0;
	low = low_value(liste);
	while (liste)
	{
		i++;
		if (low == liste->value)
			return (i);
		liste = liste->next;
	}
	return (i);
}
