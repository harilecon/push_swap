/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 07:21:01 by tsitoand          #+#    #+#             */
/*   Updated: 2026/04/02 17:48:44 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf_char_fd(int fd, char c);
int		ft_printf_string_fd(int fd, const char *s);
int		ft_printf_int_nb_fd(int fd, int n);
int		ft_printf_int_hexup_fd(int fd, unsigned int nb);
int		ft_printf_int_hexlow_fd(int fd, unsigned int nb);
int		ft_printf_address_fd(int fd, void *address);
int		ft_printf_fd(int fd, const char *s, ...);
int		ft_printf_unsigned_int_nb_fd(int fd, unsigned int n);
int		ft_printf_long_hexlow_fd(int fd, unsigned long nb);
void	ft_printf_double(int fd, double nb, int presition);

#endif
