/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:42:22 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 09:33:59 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



char	*which_algo(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf("adaptive");
		return("");
	}
	while (str[i])
		i++;
	if (i == 0)
	{
		ft_printf("--adaptive");
			return ("--adaptive");
	}
	if (i == 1)
	{
		if (ft_strcmp("--simple", str[0]) == 0)
		{
			ft_printf("--simple");
			return("simple");
		}
		else if (ft_strcmp("--adaptive", str[0]) == 0)
		{
			ft_printf("--adaptive");
			return("--adaptive");
		}
		else if (ft_strcmp("--medium", str[0]) == 0)
		{
			ft_printf("--medium");
			return("medium");
		}
		else if (ft_strcmp("--complex", str[0]) == 0)
		{
			ft_printf("--complex");
			return("complex");
		}
		else if (ft_strcmp("--complex", str[0]) == 0)
		{
			ft_printf("--bench");
			return("");
		}
		else if (ft_strcmp("--bench", str[0]) == 0)
		{
			ft_printf("--bench");
			return("");
		}
		else
		{
			ft_printf("error 1 parameter\n");
			return("");
		}
	}

	if (i > 2)
	{
		ft_printf("error too lot\n");
		return ("error");
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
			ft_printf("--complex + --bench\n");
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
			ft_printf("--medium + --bench\n");
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
			ft_printf("--simple + --bench\n");
		}
		else
			ft_printf("error pour 2\n");
	}
	return ("");
}
