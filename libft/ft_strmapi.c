/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:54:54 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/03 15:59:07 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
