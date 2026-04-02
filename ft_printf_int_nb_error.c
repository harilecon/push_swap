/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_nb_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:20:38 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:29:47 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

static int	count(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		i = 1;
	while (nbr)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static void	nbr_print(long nb)
{
	if (nb)
	{
		nbr_print(nb / 10);
		write(2, &"0123456789"[nb % 10], 1);
	}
}

int	ft_printf_int_nb_error(int n)
{
	long	nb;

	nb = n;
	if (n == 0)
	{
		write(2, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(2, "-", 1);
		nb = -nb;
	}
	nbr_print(nb);
	return (count(n));
}
