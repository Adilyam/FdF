/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:38:39 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/14 19:49:57 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int		to_line(char **heap, char **line)
{
	char *check;
	char *temp;

	check = ft_strchr(*heap, '\n');
	if (check)
	{
		temp = *heap;
		*line = ft_strndup(temp, check - temp);
		*heap = ft_strsub(temp, check - temp + 1,
				ft_strlen(temp) - (check - temp) + 1);
		free(temp);
		return (1);
	}
	return (0);
}

int		to_stack(char **heap, char **line, char *buf, int ret)
{
	char		*str;

	buf[ret] = '\0';
	if (*heap == 0)
		*heap = ft_strdup(buf);
	else
	{
		str = *heap;
		*heap = ft_strjoin(*heap, buf);
		free(str);
	}
	if (to_line(heap, line))
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*heap[256];
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, 0, 0) < 0 || fd > 256)
		return (-1);
	if (heap[fd] != NULL)
		if (to_line(&heap[fd], line))
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		if (to_stack(&heap[fd], line, buf, ret))
			return (1);
	if (heap[fd] == NULL)
		return (0);
	if (*heap[fd] == '\0')
		return (0);
	*line = ft_strdup(heap[fd]);
	ft_memdel((void **)&heap[fd]);
	return (1);
}
