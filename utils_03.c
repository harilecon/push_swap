/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:53:06 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:36:50 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_data **lst, t_data *new_value)
{
	t_data	*tmp;

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

unsigned int	stack_size(t_data *liste)
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

int	high_index(t_data *liste)
{
	t_data	*tmp;
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

static int	low_value(t_data *liste)
{
	int		low;
	t_data	*tmp;

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

unsigned int	low_index(t_data *liste)
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
