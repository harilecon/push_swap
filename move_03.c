/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:53:06 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 14:07:43 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	add_back(t_liste **lst, t_liste *new_value)
{
	t_liste	*tmp;

	if (!lst || !new_value)
		return ;
	if (!*lst)
	{
		*lst = new_value;
		new_value->next = NULL;
		new_value->previous = NULL;
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
	t_liste			*tmp;
	unsigned int	i;

	i = 0;
	tmp = liste;
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
	long	high;
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

int	low_index(t_liste *liste)
{
	t_liste	*tmp;
	long	low;
	int		i;

	if (!liste)
		return (0);
	i = 0;
	tmp = liste;
	low = liste->value;
	while (tmp)
	{
		if (tmp)
		{
			if (tmp->value < low)
				low = tmp->value;
		}
		tmp = tmp->next;
	}
	while (liste)
	{
		i++;
		if (low == liste->value)
			return (i);
		liste = liste->next;
	}
	return (i);
}
