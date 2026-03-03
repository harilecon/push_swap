/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:51:24 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/03 11:17:08 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "libft_push_swap.h"


s_stack	*create_stack(int argc, char **argv)
{
	int		i;
	s_stack	*stack;

	i = 0;
	stack = malloc(sizeof(s_stack));
	if(!stack)
		return (NULL);
	stack->value = malloc(sizeof(long *) * (argc - 1));
	if (!stack->value)
	{
		free (stack);
		return (NULL);
	}
	stack->size = argc - 1;
	while (i < (argc - 1))
	{
		stack->value[i] = ft_strlo(argv[i + 1]);
		i++;
	}
	return (stack);
}
