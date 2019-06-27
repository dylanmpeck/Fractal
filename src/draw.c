/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:51:58 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/18 16:08:06 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define IS_LEFT(x) ((x) == 0 || (x) == 2)
#define IS_TOP(x) ((x) == 0 || (x) == 1)

void	*render_quads(void *args)
{
	int		x_ind;
	int		y_ind;
	int		x_end;
	int		y_end;
	t_image	*img;

	img = ((t_args *)args)->img;
	x_end = (IS_LEFT(((t_args *)args)->quad)) ? IMG_WIDTH / 2 : IMG_WIDTH;
	y_end = (IS_TOP(((t_args *)args)->quad)) ? IMG_HEIGHT / 2 : IMG_HEIGHT;
	x_ind = (IS_LEFT(((t_args *)args)->quad)) ? 0 : IMG_WIDTH / 2;
	while (x_ind < x_end)
	{
		y_ind = (IS_TOP(((t_args *)args)->quad)) ? 0 : IMG_HEIGHT / 2;
		while (y_ind < y_end)
		{
			img->fract_funct(img, get_pixel_index(y_ind, x_ind, IMG_WIDTH));
			y_ind++;
		}
		x_ind++;
	}
	return (NULL);
}

void	draw_fractol(t_mlx *mlx)
{
	int		i;
	t_image	*img;
	t_args	args[4];

	img = mlx->img;
	i = 0;
	while (i < 4)
	{
		args[i].img = img;
		args[i].quad = i;
		pthread_create(&img->tids[i], NULL, render_quads, (void *)&args[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(img->tids[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->ptr, 0, 0);
}
