	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:24:21 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 14:55:35 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"


int	main(int argc, char **argv)
{

	t_liste	*test;
	t_liste	*lst = NULL;
	t_liste	*tmp;
	long	i;

	if (argc <= 1)
	{
		ft_printf("error argument value\n");
		return (1);
	}
	if (argc == 3)
	{
		char **tab;
		tab = ft_split(argv[3], ' ');
		while (tab)
		{
			i = 0;
			test = create_liste(char_lo(tab[0]));
			add_back(&lst, test);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			test = create_liste(char_lo(argv[i]));
			add_back(&lst, test);
			i++;
		}
	}

	//range(&lst);
	// buble(&lst);
	insertion(&lst);
	// radix(&lst);

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}


	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
