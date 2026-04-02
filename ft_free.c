/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 09:40:44 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 11:22:23 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_liste	**stack)
{
	t_liste	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}
