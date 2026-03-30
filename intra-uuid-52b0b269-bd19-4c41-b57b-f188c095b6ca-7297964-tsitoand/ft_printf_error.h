/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:21:01 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:36:02 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ERROR_H
# define FT_PRINTF_ERROR_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf_char_error(char c);
int	ft_printf_string_error(const char *s);
int	ft_printf_int_nb_error(int n);
int	ft_printf_int_hexup_error(unsigned int nb);
int	ft_printf_int_hexlow_error(unsigned int nb);
int	ft_printf_address_error(void *address);
int	ft_printf_error(const char *s, ...);
int	ft_printf_unsigned_int_nb_error(unsigned int n);
int	ft_printf_long_hexlow_error(unsigned long nb);

#endif
