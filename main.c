/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:24:21 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/18 09:53:26 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


t_liste	*create_liste(long i)
{
	t_liste	*node;

	node = malloc(sizeof(t_liste));
	if (!node)
	return NULL;

	node->value = i;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void add_back(t_liste **lst, t_liste *new_value)
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




int	stack_size(t_liste	*liste)
{
	t_liste	*tmp;
	int	i;

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
	int	i;

	if (!liste)
		return (0);

	i = 0;
	tmp = liste;
	high = liste->value;

	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->value > high)
				high = tmp->value;
		}
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
	while (str[i] && ((str[i]>= '0') && (str[i] <= '9')))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * signe);
}

/*
int	main(int argc, char **argv)
{

	t_liste	*test;
	t_liste	*lst = NULL;
	t_liste	*tmp;
	long	i;

	if (argc <= 1)
	{
		printf("error argument value\n");
		return (1);
	}
	i = 0;
	while (i < 5)
	{
		test = create_liste(i);
		add_back(&lst, test);
		i++;
	}

	rra(&lst);
	tmp = lst;
	while (tmp)
	{
		printf("%li\n", tmp->value);
		tmp = tmp->next;
	}
	printf("\ntaille de la listre = %d\n", stack_size(lst));
	printf("\nindice de la plus grande est  %d\n", high_index(lst));
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
*/


int main(int argc, char **argv)
{

}
