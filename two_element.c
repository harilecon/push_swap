/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 07:56:02 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/29 08:01:52 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_element(t_liste **stack, t_bunch **bunch_mark)
{
	if (!stack)
		return ;

	if ((*stack)->next->value < (*stack)->value)
	{
		ra(stack, bunch_mark);
		ft_printf("ra\n");
	}
}
