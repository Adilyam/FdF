/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 22:08:08 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/23 17:11:43 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		start(t_fdf *fdf)
{
	if (fdf->is_init == 1)
	{
		fdf->z = -5;
		fdf->dx = fdf->width < 200 ? 600 - fdf->width : 600 - (fdf->width / 2);
		fdf->dy = fdf->width < 450 ? -180 : -350;
		fdf->sx = fdf->width >= 50 ? 2 : 15;
		fdf->sy = fdf->width >= 50 ? 2 : 15;
	}
	draw(fdf);
	mlx_loop(fdf->mlx);
}

void		draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	x = 0;
	print_config(fdf);
	fdf->wh[0] = 0;
	fdf->wh[1] = 0;
	while (fdf->wh[0] < fdf->width || fdf->wh[1] < fdf->height - 1)
	{
		if (fdf->wh[0] == fdf->width)
		{
			fdf->wh[0] = 0;
			x = 0;
			fdf->wh[1]++;
			y += fdf->sy;
		}
		draw_lines(fdf, fdf->dx + x, fdf->dy + y);
		fdf->wh[0]++;
		x += fdf->sx;
	}
	fdf->is_init = 0;
}

void		draw_lines(t_fdf *fdf, int x, int y)
{
	float	jk[2];
	int		h;
	int		w;

	h = fdf->wh[1];
	w = fdf->wh[0];
	jk[0] = x - y;
	jk[1] = fdf->dots[h][w].z * fdf->z + x + y;
	if (w < fdf->width - 1 && h < fdf->height)
	{
		fdf->x1 = (x + fdf->sx) - y;
		fdf->y1 = fdf->dots[h][w + 1].z * fdf->z + x + fdf->sx + y;
		line(fdf, jk[0], jk[1]);
	}
	if (h < fdf->height - 1 && w < fdf->width)
	{
		fdf->x1 = x - (y + fdf->sy);
		fdf->y1 = fdf->dots[h + 1][w].z * fdf->z + x + fdf->sy + y;
		line(fdf, jk[0], jk[1]);
	}
}

void		line2(int *wh, t_fdf *fdf)
{
	wh[0] = fdf->wh[0];
	wh[1] = fdf->wh[1];
	fdf->color = fdf->dots[wh[1]][wh[0]].color;
}

void		line(t_fdf *fdf, int x0, int y0)
{
	int dxy[2];
	int sxy[2];
	int er[2];
	int wh[2];

	line2(wh, fdf);
	dxy[0] = abs(fdf->x1 - (int)x0);
	sxy[0] = x0 < fdf->x1 ? 1 : -1;
	dxy[1] = abs(fdf->y1 - (int)y0);
	sxy[1] = y0 < fdf->y1 ? 1 : -1;
	er[0] = (dxy[0] > dxy[1] ? dxy[0] : -dxy[1]) / 2;
	while (1)
	{
		if (fdf->color_pressed == 1)
			fdf->color = 255 / (wh[0] + 1) + ((wh[0] * 255) / (wh[0] + 1) << 16)
			+ (255 / (wh[1] + 1) << 8);
		mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, fdf->color);
		if (x0 == fdf->x1 && y0 == fdf->y1)
			break ;
		er[1] = er[0];
		er[1] > -dxy[0] ? er[0] -= dxy[1] : 1 == 1;
		er[1] > -dxy[0] ? x0 += sxy[0] : 1 == 1;
		er[1] < dxy[1] ? er[0] += dxy[0] : 1 == 1;
		er[1] < dxy[1] ? y0 += sxy[1] : 1 == 1;
	}
}
