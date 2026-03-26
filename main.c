/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:47:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 09:41:10 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**str;
	t_liste	*stack;
	t_liste	*tmp;
	t_argument	*my_argument;

	static t_bunch	*bunch_mark;
	int		i;

	stack = NULL;
	bunch_mark = malloc(sizeof(t_bunch));
	str = argument_table(argc, argv);

	my_argument = struct_argument(str);

	i = 0;
	if (my_argument->number)
	{
		while (my_argument->number[i])
		{
			tmp =  create_liste(char_lo(my_argument->number[i]));
			add_back(&stack, tmp);
			i++;
		}
	}

		initialisation_bunch_value(&bunch_mark);

		which_algo(my_argument->argument);

	// double disorder = compute_disorder(stack);

	free_argument(&my_argument);
	free(bunch_mark);
	free_stack(&stack);
	free_tab(str);
}

