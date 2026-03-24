/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:55:34 by tsitoand          #+#    #+#             */
/*   Updated: 2026/02/07 13:21:54 by tsitoand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
	}
	return (j);
}

static size_t	word_len(const char *s, char c, size_t start)
{
	size_t	i;
	size_t	j;

	i = start;
	j = i;
	while ((s[j] != c) && (s[j] != '\0'))
	{
		j++;
	}
	return (j - i);
}

static char	*str_copy(const char *s, size_t wlen, size_t start)
{
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (wlen + 1));
	if (!str)
		return (NULL);
	str[wlen] = '\0';
	j = 0;
	while (j < wlen)
	{
		str[j] = s[start + j];
		j++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (s == NULL)
		return (NULL);
	str = malloc (sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (NULL);
	str[word_count(s, c)] = NULL;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		str[j] = str_copy(s, word_len(s, c, i), i);
		if (!str[j])
			return ((char **)free_split(str));
		i = i + word_len(s, c, i);
		j++;
	}
	return (str);
}
