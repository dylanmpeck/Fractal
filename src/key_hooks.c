/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:47:01 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/18 15:30:19 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		window_close(t_mlx *mlx)
{
	if (mlx)
	{
		if (mlx->img)
		{
			if (mlx->img->smooth)
				ft_memdel((void **)&(mlx->img->smooth));
			ft_memdel((void **)&(mlx->img));
		}
		ft_memdel((void **)&mlx);
	}
	exit(0);
	return (0);
}

int		keydown(int key, t_mlx *mlx)
{
	if (key == 3)
		mlx->img->mouse.freeze = (mlx->img->mouse.freeze) ? 0 : 1;
	if (key == 29 || key == 18 || key == 19 || key == 20
			|| key == 21 || key == 22 || key == 23)
		select_color_palette(key, mlx->img);
	return (0);
}

int		key_press(int key, t_mlx *mlx)
{
	t_image	*img;

	img = mlx->img;
	if (key == 124)
		img->x_off += (0.05 / img->fractal.zoom);
	if (key == 123)
		img->x_off -= (0.05 / img->fractal.zoom);
	if (key == 125)
		img->y_off += (0.05 / img->fractal.zoom);
	if (key == 126)
		img->y_off -= (0.05 / img->fractal.zoom);
	if (key == 24)
		img->max_iter += 10;
	if (key == 27)
		img->max_iter -= (img->max_iter > 10) ? 10 : 0;
	if (key == 53)
		window_close(mlx);
	draw_fractol(mlx);
	return (0);
}
