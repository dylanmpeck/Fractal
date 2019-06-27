/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 19:12:10 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:49:32 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(char *str, char c)
{
	int result;
	int i;

	i = 0;
	result = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		result++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (result);
}

static char		*next_word(const char *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static size_t	word_len(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	wordcount;
	char	**array;

	if (s == NULL)
		return (NULL);
	wordcount = countwords((char *)s, c);
	array = (char **)malloc((wordcount + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < wordcount)
	{
		s = next_word(s, c);
		array[i] = ft_strsub(s, 0, word_len(s, c));
		i++;
		s += word_len(s, c);
	}
	array[i] = NULL;
	return (array);
}
