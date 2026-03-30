/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_hexlow_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:30:27 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:30:12 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

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
		write(2, &"0123456789abcdef"[nb % 16], 1);
	}
}

int	ft_printf_int_hexlow_error(unsigned int nb)
{
	if (nb == 0)
	{
		write (2, "0", 1);
		return (1);
	}
	hexlow(nb);
	return (count(nb));
}
