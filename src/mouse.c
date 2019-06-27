/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:34:28 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/17 21:51:48 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mouse	init_mouse(void)
{
	t_mouse mouse;

	mouse.freeze = 0;
	mouse.x = 0;
	mouse.y = 0;
	mouse.x_ratio = 0.5;
	mouse.y_ratio = 0.5;
	return (mouse);
}

void	do_zoom(t_mlx *mlx, int x, int y, int button)
{
	double		fx;
	double		fy;
	t_mouse		*mouse;
	t_fractal	*f;
	t_image		*img;

	img = mlx->img;
	mouse = &img->mouse;
	f = &img->fractal;
	mouse->x_ratio = (double)x / IMG_WIDTH;
	mouse->y_ratio = (double)y / IMG_HEIGHT;
	fx = interp(f->x_min, f->x_max, mouse->x_ratio);
	fy = interp(f->y_min, f->y_max, mouse->y_ratio);
	if (button == 4)
		f->zoom *= 1.1;
	if (button == 5)
		f->zoom /= 1.1;
	f->x_cent = fx;
	f->y_cent = fy;
	img->x_off = 0;
	img->y_off = 0;
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	if (x >= 0 && x <= IMG_WIDTH && y >= 0 && y <= IMG_HEIGHT)
	{
		if (button == 4 || button == 5)
		{
			do_zoom(mlx, x, y, button);
			draw_fractol(mlx);
		}
	}
	return (0);
}

int		mouse_moved(int x, int y, t_mlx *mlx)
{
	t_mouse		*mouse;
	int			is_julia;

	mouse = &mlx->img->mouse;
	is_julia = mlx->img->fractal.julia;
	if (mouse->freeze == 0)
	{
		if (x >= 0 && x <= IMG_WIDTH && y >= 0 && y <= IMG_HEIGHT)
		{
			mouse->x = x;
			mouse->y = y;
			if (is_julia)
				draw_fractol(mlx);
		}
	}
	return (0);
}
