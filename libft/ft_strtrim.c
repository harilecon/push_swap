/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:20:41 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/08 07:52:52 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*fill(size_t begin, size_t end, const char *s1, char *str)
{
	size_t	i;

	i = 0;
	while (begin + i < end)
	{
		str[i] = s1[begin + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	while (s1[begin] && is_set(s1[begin], set))
		begin++;
	end = ft_strlen(s1);
	while ((end != begin) && (is_set(s1[end - 1], set)))
		end--;
	str = ft_calloc(end - begin + 1, sizeof(char));
	if (!str)
		return (NULL);
	return (fill(begin, end, s1, str));
}
