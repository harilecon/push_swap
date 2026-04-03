/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:31:11 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:31:14 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printf_double(int fd, double nb, int presition)
{
	int	nb_int;
	int	power;
	int	i;

	power = 1;
	i = 0;
	while (i < presition)
	{
		power = power * 10;
		i++;
	}
	nb_int = (int)nb;
	ft_printf_int_nb_fd(fd, nb_int);
	ft_printf_char_fd(fd, '.');
	nb = nb - nb_int;
	nb_int = (int)(nb * power);
	ft_printf_int_nb_fd(fd, nb_int);
}
