/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long_hexlow_fd.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:43:09 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 18:02:06 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

static int	count(unsigned long nbr)
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

static void	long_hexlow(unsigned long nb)
{
	if (nb)
	{
		long_hexlow(nb / 16);
		write(2, &"0123456789abcdef"[nb % 16], 1);
	}
}

int	ft_printf_long_hexlow_fd(int fd, unsigned long nb)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	long_hexlow(nb);
	return (count(nb));
}
