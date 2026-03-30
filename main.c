/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:47:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/30 14:37:59 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**str;
	t_liste	*stack;
	t_liste	*tmp;
	t_argument	*my_argument;

	t_bunch	*bunch_mark;
	int		i;
	if (argc < 2)
		return (0);

	stack = NULL;
	bunch_mark = malloc(sizeof(t_bunch));
	if (!check_space_null(argc, argv))
	{
		ft_printf("Error\n");
		return (-1);
	}
	str = argument_table(argc, argv);

	my_argument = struct_argument(str);

	if (check_doublon(my_argument->number) || !table_check_min_max(my_argument->number))
	{
		free_tab(str);
		free(bunch_mark);
		free_argument(&my_argument);
		ft_printf("Error\n");
		return (-1);
	}

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
		which_algo(my_argument->argument, &stack ,&bunch_mark);


	free_argument(&my_argument);
	free(bunch_mark);
	free_stack(&stack);
	free_tab(str);
	return (1);
}
