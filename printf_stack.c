/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 08:36:03 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/19 15:25:22 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printf_stack(t_liste	*tmp, char *str)
{
	printf("%s\n", str);
	while (tmp)
	{
		printf("%li ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n\n");
}
