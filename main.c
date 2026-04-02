/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:47:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 18:20:59 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mother_free(t_liste **stack, t_bunch *bunch_mark,
						t_argument **my_argument)
{
	free_argument(my_argument);
	free(bunch_mark);
	free_stack(stack);
}

static void	stack_creation(char **number, t_liste **stack)
{
	t_liste	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (number)
	{
		while (number[i])
		{
			tmp = create_liste(char_to_int(number[i]));
			add_back(stack, tmp);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_liste		*stack;
	t_argument	*my_argument;
	t_bunch		*bunch_mark;

	if (argc == 1)
		return (1);
	stack = NULL;
	bunch_mark = malloc(sizeof(t_bunch));
	if (!check_space_null(argc, argv))
		return (ft_printf_fd(1 ,"fd\n"));
	my_argument = struct_argument(argument_table(argc, argv));
	if (check_doublon(my_argument->number)
		|| !table_check_min_max(my_argument->number))
	{
		ft_printf_fd(1 ,"Error\n");
		mother_free(&stack, bunch_mark, &my_argument);
		return (-1);
	}
	stack_creation(my_argument->number, &stack);
	indexation(&stack);
	initialisation_bunch_value(&bunch_mark);
	get_flag(my_argument->argument, &stack, &bunch_mark);
	mother_free(&stack, bunch_mark, &my_argument);
	return (1);
}
