/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_hexlow_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:32:34 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:32:37 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

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

int	ft_printf_int_hexlow_fd(int fd, unsigned int nb)
{
	if (nb == 0)
	{
		write (fd, "0", 1);
		return (1);
	}
	hexlow(nb);
	return (count(nb));
}
