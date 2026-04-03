/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:47:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/03 12:28:40 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mother_free(t_data **stack, t_bench *bench_mark,
		t_argument **my_argument)
{
	free_argument(my_argument);
	free(bench_mark);
	free_stack(stack);
}

static void	stack_creation(char **number, t_data **stack)
{
	t_data	*tmp;
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
	t_data		*stack;
	t_argument	*my_argument;
	t_bench		*bench_mark;

	if (argc == 1)
		return (1);
	stack = NULL;
	if (!check_space_null(argc, argv))
		return (ft_printf_fd(2, "Error\n"));
	bench_mark = malloc(sizeof(t_bench));
	my_argument = struct_argument(argument_table(argc, argv));
	if (check_doublon(my_argument->number)
		|| table_check_min_max(my_argument->number))
	{
		ft_printf_fd(2, "Error\n");
		mother_free(&stack, bench_mark, &my_argument);
		return (-1);
	}
	stack_creation(my_argument->number, &stack);
	indexation(&stack);
	initialisation_bench_value(&bench_mark);
	get_flag(my_argument->argument, &stack, &bench_mark);
	mother_free(&stack, bench_mark, &my_argument);
	return (1);
}
