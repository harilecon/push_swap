/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:24:12 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/06 20:13:56 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*condition(long nb, size_t len, char *str)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		while (len)
		{
			str[len] = nb % 10 + '0';
			len--;
			nb = nb / 10;
		}
	}
	else if (nb == 0)
	{
		str[0] = '0';
	}
	else
	{
		while (nb)
		{
			str[len] = nb % 10 + '0';
			nb = nb / 10;
			len--;
		}
	}
	return (str);
}

static size_t	n_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = n;
	len = n_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	str = condition(nb, len, str);
	return (str);
}
