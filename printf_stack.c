/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:36:03 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/22 11:49:52 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printf_stack(t_liste	*tmp, char *str)
{
	printf("%s", str);
	while (tmp)
	{
		printf("%li ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
}
	
void	printf_stack_index(t_liste	*tmp, char *str)
{
	printf("%s\n", str);
	while (tmp)
	{
		printf("%d ", tmp->index);
		tmp = tmp->next;
	}
	printf("\n\n");
}
