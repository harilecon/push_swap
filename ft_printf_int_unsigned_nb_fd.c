/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_unsigned_nb_fd.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:33:05 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:33:07 by haranivo         ###   ########.fr       */
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
		nbr = nbr / 10;
	}
	return (i);
}

static void	nbr_print(long nb)
{
	if (nb != 0)
	{
		nbr_print(nb / 10);
		write(2, &"0123456789"[nb % 10], 1);
	}
}

int	ft_printf_unsigned_int_nb_fd(int fd, unsigned int n)
{
	unsigned long	nb;

	nb = n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	nbr_print(nb);
	return (count(nb));
}
