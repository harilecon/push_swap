/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:24:21 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/23 13:36:22 by tsitoand         ###   ########.fr       */
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
//	ft_printf("size = %d\n",stack_size(lst));
// //	ft_printf("%li", greatest(lst));
// 	int size = stack_size(lst);
// 	indexation(&lst);

	// ft_printf_stack(lst, "");
	// for (int i = 0; i < size; i++)
	// {
	// 	ft_printf("%d ",tab[i]);
	// }
//	ft_printf("\n");

	// ft_printf_stack_index(lst, "");
	// ft_printf_stack(lst, "");
	// ft_printf("max bits = %d\n", max_bits (lst));
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	return (0);
}
