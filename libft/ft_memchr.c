/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:02:22 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/06 22:47:57 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p_s;

	p_s = s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (p_s[i] == (unsigned char) c)
			return ((void *)(p_s + i));
		i++;
	}
	return (NULL);
}
