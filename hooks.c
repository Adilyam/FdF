/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 19:07:15 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/23 17:12:01 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom(int keycode, t_fdf *key)
{
	if (keycode == 69 && key->sx * 2 <= 500 && key->sy * 2 <= 500)
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 2;
		key->sy *= 2;
		key->z *= 2;
		draw(key);
	}
	if (keycode == 78 && key->sx * 0.5 >= 1 && key->sy * 0.5 >= 1 &&
		(-key->z * 0.5 >= 1 || key->z * 0.5 >= 1))
	{
		mlx_clear_window(key->mlx, key->win);
		key->sx *= 0.5;
		key->sy *= 0.5;
		key->z *= 0.5;
		draw(key);
	}
}

void		to_init_pos(int keycode, t_fdf *key)
{
	if (keycode == 36)
	{
		mlx_clear_window(key->mlx, key->win);
		key->is_init = 1;
		start(key);
	}
}

void		move(int keycode, t_fdf *key)
{
	if (keycode >= 123 && keycode <= 126)
	{
		mlx_clear_window(key->mlx, key->win);
		if (keycode == 123)
		{
			key->dx -= 10;
			key->dy += 10;
		}
		if (keycode == 126)
		{
			key->dx -= 10;
			key->dy -= 10;
		}
		if (keycode == 124)
		{
			key->dy -= 10;
			key->dx += 10;
		}
		if (keycode == 125)
		{
			key->dy += 10;
			key->dx += 10;
		}
		draw(key);
	}
}

void		color(int keycode, t_fdf *key)
{
	if (keycode == 49)
	{
		if (key->color_pressed == 1)
			key->color_pressed = 0;
		else
			key->color_pressed = 1;
		mlx_clear_window(key->mlx, key->win);
		draw(key);
	}
}

int			keyboard(int keycode, t_fdf *key)
{
	if (keycode == 53)
		end();
	if (keycode == 75)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z++;
		draw(key);
	}
	if (keycode == 67)
	{
		mlx_clear_window(key->mlx, key->win);
		key->z--;
		draw(key);
	}
	to_init_pos(keycode, key);
	color(keycode, key);
	zoom(keycode, key);
	move(keycode, key);
	return (0);
}
