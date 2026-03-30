/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:38:50 by tsitoand          #+#    #+#             */
/*   Updated: 2026/03/26 11:36:46 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_error.h"

static int	if_statement(const char *s, int i, int j)
{
	if (s[i] == '%')
	{
		if (s[i + 1] == '\0')
		{
			if ((i > 1) && (s[i - 1] != '%'))
				return (-1);
		}
		j = 0;
		while ("cspdiuxX%"[j])
		{
			if ("cspdiuxX%"[j] == s[i + 1])
				break ;
			j++;
		}
		if ("cspdiuxX%"[j] == '\0')
		{
			if ((i > 1) && (s[i - 1] != '%'))
				return (-1);
		}
	}
	return (1);
}

static int	test_string(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (if_statement(s, i, j) == -1)
			return (-1);
		i++;
	}
	return (1);
}

static int	test_char(char c)
{
	int	i;

	i = 0;
	while ("cspdiuxX%"[i])
	{
		if ("cspdiuxX%"[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	condition(const char *s, int i, va_list args)
{
	if (s[i] != '%')
		return (ft_printf_char_error(s[i]));
	else if (((s[i + 1] == 'd')) || (s[i + 1] == 'i'))
		return (ft_printf_int_nb_error(va_arg(args, int)));
	else if (s[i + 1] == 'x')
		return (ft_printf_int_hexlow_error(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'X')
		return (ft_printf_int_hexup_error(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'u')
		return (ft_printf_unsigned_int_nb_error(va_arg(args, unsigned int)));
	else if (s[i + 1] == 'p')
		return (ft_printf_address_error(va_arg(args, void *)));
	else if (s[i + 1] == 's')
		return (ft_printf_string_error(va_arg(args, char *)));
	else if (s[i + 1] == 'c')
		return (ft_printf_char_error(va_arg(args, int)));
	else if (s[i + 1] == '%')
		return (ft_printf_char_error('%'));
	return (0);
}

int	ft_printf_error(const char *s, ...)
{
	int		i;
	int		len;
	va_list	args;

	len = 0;
	if (!s)
		return (-1);
	i = 0;
	if (test_string(s) < 0)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		len = len + condition (s, i, args);
		if ((s[i] == '%') && test_char(s[i + 1]))
			i++;
		i++;
	}
	va_end(args);
	return (len);
}
