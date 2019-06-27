/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 18:21:57 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:47:41 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*newstr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		newstr[i] = (*f)(s[i]);
		i++;
	}
	return (newstr);
}
