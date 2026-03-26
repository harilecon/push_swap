/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:42:22 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 13:05:46 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	which_algo(char **str, t_liste **stack, t_bunch **bunch_mark)
{
	double disorder;
	int	i;

	disorder = compute_disorder(*stack);
	i = 0;
	if (!str)
	{
		choose_your_destiny(stack, bunch_mark);
		return ;
	}
	while (str[i])
		i++;


	if (i == 1)
	{
		if (ft_strcmp("--simple", str[0]) == 0)
		{
			insertion(stack, bunch_mark);
			return ;
		}
		else if (ft_strcmp("--adaptive", str[0]) == 0)
		{
			ft_printf("--adaptive");
			return ;
		}
		else if (ft_strcmp("--medium", str[0]) == 0)
		{
			range(stack, bunch_mark);
			return ;
		}
		else if (ft_strcmp("--complex", str[0]) == 0)
		{
			radix(stack, bunch_mark);
			return ;
		}
		else if (ft_strcmp("--complex", str[0]) == 0)
		{
			ft_printf("--bench");
			return ;
		}
		else if (ft_strcmp("--bench", str[0]) == 0)
		{
			choose_your_destiny(stack, bunch_mark);
			bunch(disorder ,*bunch_mark);
			return ;
		}
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}

	if (i > 2)
	{
		ft_printf("error too lot\n");
		return ;
	}

	if ( i == 2)
	{
		if (str[0] && str[1] &&
			(
				(ft_strcmp(str[0], "--adaptive") == 0 &&
				 ft_strcmp(str[1], "--bench") == 0)
				||
				(ft_strcmp(str[0], "--bench") == 0 &&
				 ft_strcmp(str[1], "--adaptive") == 0)
			)
		)
		{
			ft_printf("--adaptive + --bench\n");
			return ;
		}
		else if (str[0] && str[1] &&
			(
				(ft_strcmp(str[0], "--complex") == 0 &&
				 ft_strcmp(str[1], "--bench") == 0)
				||
				(ft_strcmp(str[0], "--bench") == 0 &&
				 ft_strcmp(str[1], "--complex") == 0)
			)
		)
		{
			radix(stack, bunch_mark);
			bunch(disorder ,*bunch_mark);
			return ;
		}
		else if (str[0] && str[1] &&
			(
				(ft_strcmp(str[0], "--medium") == 0 &&
				 ft_strcmp(str[1], "--bench") == 0)
				||
				(ft_strcmp(str[0], "--bench") == 0 &&
				 ft_strcmp(str[1], "--medium") == 0)
			)
		)
		{
			range(stack,bunch_mark);
			bunch(disorder ,*bunch_mark);
			return ;
		}
		else if (str[0] && str[1] &&
			(
				(ft_strcmp(str[0], "--simple") == 0 &&
				 ft_strcmp(str[1], "--bench") == 0)
				||
				(ft_strcmp(str[0], "--bench") == 0 &&
				 ft_strcmp(str[1], "--simple") == 0)
			)
		)
		{
			insertion(stack, bunch_mark);
			bunch(disorder ,*bunch_mark);
			return ;
		}
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}
}
