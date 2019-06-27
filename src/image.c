/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 22:11:41 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/18 15:11:09 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_set_pixel(t_image *img, int x, int y, int color)
{
	*(int *)(img->addr + ((y * IMG_WIDTH + x) * img->bpp)) = color;
}

t_image	*image_init(t_mlx *mlx, char *arg)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	img->max_iter = MAX_ITERATIONS;
	img->x_off = 0;
	img->y_off = 0;
	img->ptr = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
									&img->size, &img->endian);
	img->bpp /= 8;
	if ((setup_fractal(img, arg)) == 0)
		return (NULL);
	img->mouse = init_mouse();
	init_color_struct(img);
	img->smooth = (double *)malloc(sizeof(double) * IMG_WIDTH * IMG_HEIGHT);
	return (img);
}
