/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:21:01 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/14 12:42:58 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf_char(char c);
int	ft_printf_string(const char *s);
int	ft_printf_int_nb(int n);
int	ft_printf_int_hexup(unsigned int nb);
int	ft_printf_int_hexlow(unsigned int nb);
int	ft_printf_address(void *address);
int	ft_printf(const char *s, ...);
int	ft_printf_unsigned_int_nb(unsigned int n);
int	ft_printf_long_hexlow(unsigned long nb);

#endif
