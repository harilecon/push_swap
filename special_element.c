/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 11:24:20 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/31 11:26:31 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element(t_liste	**stack, t_bunch **bunch_mark)
{
	if ((*stack)->value > (*stack)->next->value)
		ra(stack, bunch_mark);
}
