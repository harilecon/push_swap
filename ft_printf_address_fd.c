/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:01:33 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:56:57 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_address_fd(int fd, void *address)
{
	unsigned long	ad;
	int				i;

	i = 0;
	if (!address)
		return (ft_printf_string_fd(fd, "(nil)"));
	ad = (unsigned long)address;
	i = ft_printf_string_fd(fd, "0x");
	i = i + ft_printf_long_hexlow_fd(fd, ad);
	return (i);
}
