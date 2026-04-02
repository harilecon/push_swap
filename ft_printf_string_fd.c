/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:25:10 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:46:47 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_string_fd(int fd, const char *s)
{
	size_t	i;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}
