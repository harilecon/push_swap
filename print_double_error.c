/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 11:50:55 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 13:00:05 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	ft_printf_double(double nb, int presition)
{
	int	nb_int;
	int power;
	int	i;

	power = 1;
	i = 0;
	while (i < presition)
	{
		power = power * 10;
		i++;
	}
	nb_int = (int)nb;
	ft_printf_int_nb_error(nb_int);
	ft_printf_char_error('.');
	nb = nb - nb_int;
	nb_int = (int) (nb * power);
	ft_printf_int_nb_error(nb_int);
}


