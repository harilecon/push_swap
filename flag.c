/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:56:59 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/02 18:21:29 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*is_flag(char *str)
{
	if (!str)
		return (NULL);
	if (ft_strcmp(str, "--simple") == 0)
		return ("simple");
	if (ft_strcmp(str, "--medium") == 0)
		return ("medium");
	if (ft_strcmp(str, "--complex") == 0)
		return ("complex");
	if (ft_strcmp(str, "--adaptive") == 0)
		return ("adaptive");
	else
		return (NULL);
	return (NULL);
}

static void	algo_call(char *str, t_liste **stack, t_bunch **bunch_mark)
{
	if (ft_strcmp(str, "simple") == 0)
		insertion(stack, bunch_mark);
	else if (ft_strcmp(str, "medium") == 0)
		range(stack, bunch_mark);
	else if (ft_strcmp(str, "complex") == 0)
		radix(stack, bunch_mark);
	else if (ft_strcmp(str, "adaptive") == 0)
		choose_your_destiny(stack, bunch_mark);
	else
		ft_printf_fd(1, "Error\n");
	return ;
}

static void	one_noflag(int i, char **str, t_liste **stack, t_bunch **bunch_mark)
{
	double	disorder;

	disorder = compute_disorder(*stack);
	if (!str)
		choose_your_destiny(stack, bunch_mark);
	else if (i == 1)
	{
		if (is_flag(str[0]))
		{
			(*bunch_mark)->strategy = is_flag(str[0]);
			algo_call(is_flag(str[0]), stack, bunch_mark);
		}
		else if (ft_strcmp(str[0], "--bench") == 0)
		{
			choose_your_destiny(stack, bunch_mark);
			bunch(disorder, *bunch_mark);
		}
		else
		{
			ft_printf_fd(1,"Error\n");
		}
	}
	return ;
}

static void	multi_flag(char **str, t_liste **stack, t_bunch **bunch_mark)
{
	double	disorder;

	disorder = compute_disorder(*stack);
	if (!str)
		choose_your_destiny(stack, bunch_mark);
	if (ft_strcmp(str[0], "--bench") == 0 && is_flag(str[1]))
	{
		(*bunch_mark)->strategy = is_flag(str[1]);
		algo_call(is_flag(str[1]), stack, bunch_mark);
		bunch(disorder, *bunch_mark);
		return ;
	}
	else if (is_flag(str[0]) && ft_strcmp(str[1], "--bench") == 0)
	{
		(*bunch_mark)->strategy = is_flag(str[0]);
		algo_call(is_flag(str[0]), stack, bunch_mark);
		bunch(disorder, *bunch_mark);
		return ;
	}
	else
		ft_printf_fd(1, "Error\n");
	return ;
}

void	get_flag(char **str, t_liste **stack, t_bunch **bunch_mark)
{
	int		i;

	i = 0;
	if (!str)
		choose_your_destiny(stack, bunch_mark);
	else
		while (str[i])
			i++;
	if (i == 1)
		one_noflag(i, str, stack, bunch_mark);
	if (i == 2)
	{
		multi_flag(str, stack, bunch_mark);
	}
	else if (i > 2)
		ft_printf_fd(1, "Error\n");
	return ;
}
