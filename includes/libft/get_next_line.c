/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 18:41:35 by dpeck             #+#    #+#             */
/*   Updated: 2018/11/28 19:47:54 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		create_new_line(char **line, int fd, char **store, int ret)
{
	int			len;
	char		*str;

	ret = 1;
	len = 0;
	while (store[fd][len] != '\n' && store[fd][len])
		len++;
	if (store[fd][len] == '\n')
	{
		*line = ft_strsub(store[fd], 0, len);
		str = ft_strdup(store[fd] + len + 1);
		free(store[fd]);
		store[fd] = str;
		if (store[fd][0] == '\0')
			ft_strdel(&store[fd]);
	}
	else if (store[fd][len] == '\0')
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	static char	*store[255];

	ret = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strnew(1);
		str = ft_strjoin(store[fd], buf);
		free(store[fd]);
		store[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (store[fd] == NULL || store[fd][0] == '\0'))
		return (0);
	return (create_new_line(line, fd, store, ret));
}
