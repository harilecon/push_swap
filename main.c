/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:24:21 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/16 19:45:37 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <endian.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_liste
{
	long	value;
	struct s_liste	*next;
	struct s_liste	*previous;
}		t_liste;

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

void	sa(t_liste **a)
{
	t_liste	*first;
	t_liste	*second;

	if (!a || !(*a) || !(*a)->next)
		return ;

	first = *a;
	second = (*a)->next;

	first->previous = second;
	first->next = second->next;

	second->next = first;
	second->previous = NULL;

	*a = second;

	if (first->next)
		first->next->previous = first;
}

void	sb(t_liste **b)
{
	t_liste	*first;
	t_liste	*second;

	if (!b || !(*b) || !(*b)->next)
		return ;

	first = *b;
	second = (*b)->next;

	first->previous = second;
	first->next = second->next;

	second->next = first;
	second->previous = NULL;

	*b = second;

	if (first->next)
		first->next->previous = first;
}
void ss(t_liste **a, t_liste **b)
{
	sa(a);
	sb(b);
}

void	ra(t_liste **a)
{
	t_liste	*last;
	t_liste	*first;

	if (!a || !*a || !(*a)->next)
		return;

	last = *a;
	first = *a;

	while (last->next)
		last = last->next;

	(*a) = (*a)->next;
	(*a)->previous = NULL;

	last->next = first;
	first->previous = last;
	first->next = NULL;
}

void	rb(t_liste **b)
{
	t_liste	*last;
	t_liste	*first;

	if (!b || !*b || !(*b)->next)
		return;

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
void rr(t_liste **a, t_liste **b)
{
	ra(a);
	rb(b);
}

void rra(t_liste **a)
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

void rrb(t_liste **b)
{
	t_liste	*last;
	t_liste	*b_last;

	if (!b || !*b || !(*b)->next)
		return ;

	last = *b;

	while (last->next)
		last = last->next;

	b_last = last->previous;
	b_last->next = NULL;

	last->next = *b;
	last->previous = NULL;

	(*b)->previous = last;
	*b = last;
}

void	rrr(t_liste **a, t_liste **b)
{
	rra(a);
	rrb(b);
}

void	pa(t_liste **a, t_liste **b)
{
	t_liste	*tmp;

	if (!a || !b || !*b)
		return ;

	tmp = *b;

	*b = (*b)->next;
	if (*b)
		(*b)->previous = NULL;

	tmp->next = *a;
	tmp->previous = NULL;

	if (*a)
		(*a)->previous = tmp;

	*a = tmp;
}

void	pb(t_liste **a, t_liste **b)
{
	t_liste	*tmp;

	if (!b || !a || !*a)
		return ;
	tmp = *a;

	*a = (*a)->next;

	if (*a)
		(*a)->previous = NULL;

	tmp->next = *b;
	tmp->previous = NULL;

	if (*b)
		(*b)->previous = tmp;

	*b = tmp;
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

int	main(void)
{
	t_liste	*test;
	t_liste	*lst = NULL;
	t_liste	*tmp;
	long	i;
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
