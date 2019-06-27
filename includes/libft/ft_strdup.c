/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:19:34 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/23 12:46:04 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*result;
	const char	*psrc;
	char		*pdest;

	result = (char *)malloc(ft_strlen(str) + 1);
	psrc = str;
	pdest = result;
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	while (*psrc)
	{
		*pdest = *psrc;
		pdest++;
		psrc++;
	}
	*pdest = '\0';
	return (result);
}
