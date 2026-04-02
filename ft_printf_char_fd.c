/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 08:59:42 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:45:58 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fd.h"

int	ft_printf_char_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}
