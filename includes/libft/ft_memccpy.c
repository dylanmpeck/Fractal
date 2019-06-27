/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:00:20 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:42:07 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dst)[i - 1] == ch)
			return (&((unsigned char *)dst)[i]);
	}
	return (NULL);
}
