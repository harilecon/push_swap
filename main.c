/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:24:21 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 07:48:01 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		printf("error argument value\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		test = create_liste(char_lo(argv[i]));
		add_back(&lst, test);
		i++;
	}

	range(&lst);
	// buble(&lst);
//	insertion(&lst);
	// radix(&lst);
//	printf("size = %d\n",stack_size(lst));
// //	printf("%li", greatest(lst));
// 	int size = stack_size(lst);
// 	indexation(&lst);

	// printf_stack(lst, "");
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d ",tab[i]);
	// }
//	printf("\n");

	// printf_stack_index(lst, "");
	// printf_stack(lst, "");
	// printf("max bits = %d\n", max_bits (lst));
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
