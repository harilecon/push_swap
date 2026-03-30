/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:01:33 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:37:33 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

int	ft_printf_address_error(void *address)
{
	unsigned long	ad;
	int				i;

	i = 0;
	if (!address)
		return (ft_printf_string_error("(nil)"));
	ad = (unsigned long)address;
	i = ft_printf_string_error("0x");
	i = i + ft_printf_long_hexlow_error(ad);
	return (i);
}
