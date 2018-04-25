/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:43:20 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/15 16:23:52 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdlib.h>
# include <math.h>

# define WIDTH 1600
# define HEIGHT 1200

typedef struct		s_dots
{
	double			x;
	double			y;
	int				z;
	int				color;
}					t_dots;

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	t_dots			**dots;
	int				height;
	int				width;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				color_pressed;
	int				wh[2];
	int				x1;
	int				y1;
	int				color;
	int				is_init;
}					t_fdf;

void				print_config(t_fdf *fdf);
int					ft_read(t_fdf *fdf);
void				start(t_fdf *fdf);
int					color_map_1(t_fdf *draw, int w, int h);
void				draw(t_fdf *fdf);
void				draw_lines(t_fdf *fdf, int x, int y);
void				line(t_fdf *fdf, int x0, int y0);
void				convert_xyz(t_fdf *fdf, int x, int y, int w, int h);
int					keyboard(int keycode, t_fdf *key);
void				move(int keycode, t_fdf *key);
void				zoom(int keycode, t_fdf *key);
int					end(void);

#endif
