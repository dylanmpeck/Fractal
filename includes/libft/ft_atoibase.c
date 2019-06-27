/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:18:40 by dpeck             #+#    #+#             */
/*   Updated: 2018/11/28 16:34:20 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoibase(const char *str, int str_base)
{
	int		i;
	int		result;
	char	*basechar;
	int		num;

	i = 0;
	result = 0;
	basechar = "0123456789ABCDEFabcdef";
	while ((str[i]) && (ft_strchr(basechar, (int)str[i]) != NULL))
	{
		if (str[i] >= 'A')
		{
			if (str[i] >= 'a')
				num = str[i] - ('a' - 10);
			else
				num = str[i] - ('A' - 10);
		}
		else
			num = str[i] - '0';
		result = result * str_base + num;
		i++;
	}
	return (result);
}
