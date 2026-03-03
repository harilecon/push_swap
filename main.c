/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:00:09 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/03 11:16:54 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft_push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	s_stack *stack_a;

	if (argc <= 1)
	{
		printf("no parameter found\n");
		return (-1);
	}
	stack_a = create_stack(argc, argv);
	if (!stack_a)
	{
		printf("error stack creation\n");
		return (-1);
	}

	printf("stack size = %d\n", stack_a->size);
	i = 0;
	while (i < stack_a->size)
	{
		printf("%d = %li\n",i, stack_a->value[i]);
		i++;
	}
	free(stack_a->value);
	free(stack_a);
	return (0);
}
