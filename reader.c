/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:16:09 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/23 13:48:15 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_height(t_fdf *fdf, char *line)
{
	int		x;
	char	**tab;

	x = 0;
	tab = ft_strsplit(line, ' ');
	while (tab[x])
	{
		if (ft_isdigit(tab[x][0]) || tab[x][0] == '-')
			free(tab[x++]);
		else
		{
			ft_putendl("map error");
			exit(0);
		}
	}
	fdf->width = x;
	free(line);
	free(tab);
	fdf->height++;
	return (0);
}

int			check(t_fdf *fdf)
{
	char	*line;
	int		ret;

	fdf->width = 0;
	fdf->height = 0;
	while ((ret = get_next_line(fdf->fd, &line)) > 0)
		get_height(fdf, line);
	close(fdf->fd);
	fdf->fd = open(fdf->name, O_RDONLY);
	return (0);
}

int			get_color(char *val)
{
	size_t	i;

	i = 0;
	if (ft_strchr(val, ','))
	{
		while (val[i] != ',')
			i++;
		return (ft_atoi_base(val + i + 3, 16));
	}
	return (0xFFFFFF);
}

t_dots		fill_struct(int i, int j, char *val)
{
	t_dots dot;

	dot.x = i;
	dot.y = j;
	dot.z = ft_atoi(val);
	dot.color = get_color(val);
	return (dot);
}

int			ft_read(t_fdf *fdf)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;
	int		ret;

	i = 0;
	check(fdf);
	fdf->dots = ft_memalloc(sizeof(t_dots*) * fdf->height);
	while ((ret = get_next_line(fdf->fd, &line)) > 0)
	{
		j = 0;
		tab = ft_strsplit(line, ' ');
		fdf->dots[i] = ft_memalloc(sizeof(t_dots) * fdf->width);
		while (tab[j])
		{
			fdf->dots[i][j] = fill_struct(i, j, tab[j]);
			free(tab[j]);
			j++;
		}
		free(tab);
		free(line);
		i++;
	}
	return ((ret == -1) ? (-1) : 1);
}
