/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:37:23 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/17 22:42:08 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_iterations(t_image *img, t_fractal *f, t_complex *z, t_complex *c)
{
	int		iterations;
	double	tmp_z_r;
	double	tmp_z_i;

	tmp_z_r = -999999;
	tmp_z_i = -999999;
	iterations = 0;
	while (z->r * z->r + z->i * z->i <= 4.0 && iterations < img->max_iter)
	{
		z->old_r = z->r;
		z->r = (z->r * z->r) + -1 * (z->i * z->i) + c->r;
		z->i = 2 * z->old_r * z->i + c->i;
		z->r = (f->burning) ? fabs(z->r) : z->r;
		z->i = (f->burning) ? fabs(z->i) : z->i;
		if (z->r == tmp_z_r && z->i == tmp_z_i)
		{
			iterations = img->max_iter;
			break ;
		}
		tmp_z_r = z->r;
		tmp_z_i = z->i;
		iterations++;
	}
	return (iterations);
}

double	escape_time(t_image *img, t_fractal f)
{
	int		iterations;

	iterations = get_iterations(img, &f, &f.z, &f.c);
	if (iterations != img->max_iter)
	{
		return ((float)iterations + 1 -
				log(log(f.z.r * f.z.r + f.z.i * f.z.i)) / log(2.0));
	}
	return ((float)iterations);
}

void	mandelbrot(void *image, int pix_ind)
{
	t_fractal		m;
	t_image			*img;

	img = (t_image *)image;
	m = img->fractal;
	m.x = pix_ind % IMG_WIDTH;
	m.y = pix_ind / IMG_WIDTH;
	m = get_fract_min_max(img, m);
	img->fractal = m;
	m.c.r = interp(m.x_min, m.x_max, (float)m.x / IMG_WIDTH);
	m.c.i = interp(m.y_min, m.y_max, (float)m.y / IMG_HEIGHT);
	m.z.r = 0;
	m.z.i = 0;
	img->smooth[pix_ind] = escape_time(img, m);
	image_set_pixel(img, m.x, m.y, make_color(img, img->smooth[pix_ind]));
}

void	julia(void *image, int pix_ind)
{
	t_fractal		j;
	t_image			*img;

	img = (t_image *)image;
	j = img->fractal;
	j.x = pix_ind % IMG_WIDTH;
	j.y = pix_ind / IMG_WIDTH;
	j = get_fract_min_max(img, j);
	img->fractal = j;
	j.c.r = interp(-j.x_wid / 2, j.x_wid / 2, img->mouse.x / IMG_WIDTH);
	j.c.i = interp(-j.x_wid / 2, j.x_wid / 2, img->mouse.y / IMG_HEIGHT);
	j.z.r = interp(j.x_min, j.x_max, (float)j.x / IMG_WIDTH);
	j.z.i = interp(j.y_min, j.y_max, (float)j.y / IMG_HEIGHT);
	img->smooth[pix_ind] = escape_time(img, j);
	image_set_pixel(img, j.x, j.y, make_color(img, img->smooth[pix_ind]));
}
