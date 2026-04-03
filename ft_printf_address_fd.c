/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 12:31:27 by haranivo          #+#    #+#             */
/*   Updated: 2026/04/03 12:31:35 by haranivo         ###   ########.fr       */
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
