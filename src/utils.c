/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:34:28 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/17 22:42:22 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_pixel_index(int row, int col, int width)
{
	return (row * width + col);
}

double		interp(double start, double end, double percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - percent) + (end * percent));
}

t_fractal	get_fract_min_max(t_image *img, t_fractal f)
{
	double	x_wid;
	double	y_wid;

	x_wid = f.x_wid / img->fractal.zoom;
	y_wid = f.y_wid / img->fractal.zoom;
	f.x_min = f.x_cent + img->x_off - x_wid * (img->mouse.x_ratio);
	f.x_max = f.x_cent + img->x_off + x_wid * (1 - img->mouse.x_ratio);
	f.y_min = f.y_cent + img->y_off - y_wid * (img->mouse.y_ratio);
	f.y_max = f.y_cent + img->y_off + y_wid * (1 - img->mouse.y_ratio);
	return (f);
}
