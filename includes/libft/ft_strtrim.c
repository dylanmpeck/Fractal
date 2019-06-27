/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:55:12 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:50:00 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_whitespace(const char *s, size_t n)
{
	if ((s[n] == ' ' || s[n] == '\n' || s[n] == '\t') && s[n])
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	size_t	begin;
	size_t	end;
	size_t	i;
	char	*newstr;

	i = 0;
	begin = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (check_whitespace(s, begin))
		begin++;
	while (check_whitespace(s, end - 1))
		end--;
	if ((begin == 0 && end == ft_strlen(s) - 1) || !ft_strlen(s))
		return ((char *)s);
	if (end < begin)
		end = begin;
	newstr = ft_strnew(end - begin);
	if (newstr == NULL)
		return (NULL);
	return (ft_strncpy(newstr, s + begin, end - begin));
}
