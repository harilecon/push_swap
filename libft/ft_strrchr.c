/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:34:02 by tsitoand          #+#    #+#             */
/*   Updated: 2026/01/23 20:53:56 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;
	char	d;

	d = (char) c;
	len_s = ft_strlen(s);
	while ((len_s > 0) && (s[len_s] != d))
	{
		len_s--;
	}
	if ((len_s == 0) && (s[len_s] != d))
		return (NULL);
	return ((char *) s + len_s);
}
