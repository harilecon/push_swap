/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_hexup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:58:48 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/24 19:38:40 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i);
}

static void	hexup(unsigned int nb)
{
	if (nb)
	{
		hexup(nb / 16);
		write(1, &"0123456789ABCDEF"[nb % 16], 1);
	}
}

int	ft_printf_int_hexup(unsigned int nb)
{
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	hexup(nb);
	return (count (nb));
}
