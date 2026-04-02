/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_hexup_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:58:48 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:58:46 by tsitoand         ###   ########.fr       */
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

static void	hexup(unsigned int nb)
{
	if (nb)
	{
		hexup(nb / 16);
		write(2, &"0123456789ABCDEF"[nb % 16], 1);
	}
}

int	ft_printf_int_hexup_fd(int fd, unsigned int nb)
{
	if (nb == 0)
	{
		write (fd, "0", 1);
		return (1);
	}
	hexup(nb);
	return (count (nb));
}
