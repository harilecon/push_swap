/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:42:57 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/07 13:19:40 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (s1[i]) && (s2[i]) && (s1[i] == s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
