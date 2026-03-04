/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:09:13 by tsitoand          #+#    #+#             */
/*   Updated: 2026/01/26 13:10:33 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	str_len;
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
		str_len = s_len - start;
	else
		str_len = len;
	str = ft_calloc(str_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
