/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atilegen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:46:05 by atilegen          #+#    #+#             */
/*   Updated: 2018/04/15 15:47:34 by atilegen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_config(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 14, 8, 0xFFE4E1,
					"MOVE  : up down left right");
	mlx_string_put(fdf->mlx, fdf->win, 14, 24, 0xFFE4E1,
					"ZOOM  : + - (numeric)");
	mlx_string_put(fdf->mlx, fdf->win, 14, 40, 0xFFE4E1, "DEEP  : * /");
	mlx_string_put(fdf->mlx, fdf->win, 14, 56, 0xFFE4E1, "RESET : enter");
	mlx_string_put(fdf->mlx, fdf->win, 14, 74, 0xFFE4E1, "COLOR : space");
	mlx_string_put(fdf->mlx, fdf->win, 14, 88, 0xFFE4E1, "EXIT  : esc");
	mlx_string_put(fdf->mlx, fdf->win, 90, 104, 0xFFE4E1,
					ft_strrchr(fdf->name, '/') + 1);
	mlx_string_put(fdf->mlx, fdf->win, 14, 104, 0xFFE4E1, "FILE  : ");
}

void	init(t_fdf *fdf)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, fdf->name);
	fdf->win = win_ptr;
	fdf->mlx = mlx_ptr;
	mlx_hook(fdf->win, 2, 5, keyboard, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, end, fdf);
	fdf->color_pressed = 0;
	fdf->is_init = 1;
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 2)
	{
		fdf.name = av[1];
		fdf.fd = open(fdf.name, O_RDONLY);
		if (ft_read(&fdf) == -1)
		{
			ft_putendl("error");
			exit(0);
		}
		init(&fdf);
		start(&fdf);
	}
	else
		ft_putendl("usage: ./fdf [-file]");
	return (0);
}
