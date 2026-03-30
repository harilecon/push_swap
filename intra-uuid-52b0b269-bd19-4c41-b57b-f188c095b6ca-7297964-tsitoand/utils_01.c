/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:45:00 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 09:46:09 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 && s2)
		return(s2[i]);
	if (s1 && !s2)
		return (s1[i]);
	if (!s1 && !s2)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
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
