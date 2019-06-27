/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:01:36 by dpeck             #+#    #+#             */
/*   Updated: 2018/11/19 21:07:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	ch;

	ch = c;
	while (*str)
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}
