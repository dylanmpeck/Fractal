/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:56:46 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:49:21 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(str);
	ch = c;
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (NULL);
}
