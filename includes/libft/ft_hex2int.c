/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex2int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:51:55 by dpeck             #+#    #+#             */
/*   Updated: 2018/11/19 20:38:24 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_hex2int(char *a, unsigned int len)
{
	unsigned int	i;
	unsigned long	val;

	val = 0;
	i = 0;
	while (i < len)
	{
		if (a[i] <= 57)
			val += (a[i] - 48) * (1 << (4 * (len - 1 - i)));
		else
			val += (a[i] - 55) * (1 << (4 * (len - 1 - i)));
		i++;
	}
	return (val);
}
