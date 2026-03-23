/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_hexlow.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:30:27 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/14 12:06:14 by tsitoand         ###   ########.fr       */
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

static void	hexlow(unsigned int nb)
{
	if (nb)
	{
		hexlow(nb / 16);
		write(1, &"0123456789abcdef"[nb % 16], 1);
	}
}

int	ft_printf_int_hexlow(unsigned int nb)
{
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	hexlow(nb);
	return (count(nb));
}
