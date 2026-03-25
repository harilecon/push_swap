/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:01:33 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/24 19:38:33 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_address(void *address)
{
	unsigned long	ad;
	int				i;

	i = 0;
	if (!address)
		return (ft_printf_string("(nil)"));
	ad = (unsigned long)address;
	i = ft_printf_string("0x");
	i = i + ft_printf_long_hexlow(ad);
	return (i);
}
