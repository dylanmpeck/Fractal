/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:51:31 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:41:42 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(long n)
{
	size_t	count;

	count = 0;
	if (n < 0)
		n = -n;
	count++;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	long	v;
	size_t	length;
	char	*newstr;
	int		neg;

	v = n;
	neg = (v < 0 ? 1 : 0);
	length = num_len(v);
	newstr = ft_strnew(length + neg);
	if (newstr == NULL)
		return (NULL);
	if (v < 0)
	{
		newstr[0] = '-';
		v = -v;
	}
	while (length > 0)
	{
		newstr[length + neg - 1] = (v % 10) + '0';
		length--;
		v /= 10;
	}
	return (newstr);
}
