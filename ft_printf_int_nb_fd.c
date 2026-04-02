/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_nb_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:20:38 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:51:11 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

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

static void	nbr_print(int fd, long nb)
{
	if (nb)
	{
		nbr_print(fd, nb / 10);
		write(fd, &"0123456789"[nb % 10], 1);
	}
}

int	ft_printf_int_nb_fd(int fd, int n)
{
	long	nb;

	nb = n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	nbr_print(fd, nb);
	return (count(n));
}
