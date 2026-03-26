/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:25:10 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:28:51 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

int	ft_printf_string_error(const char *s)
{
	size_t	i;

	if (!s)
	{
		write(2, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	return (i);
}
