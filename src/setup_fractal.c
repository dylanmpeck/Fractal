/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:29:59 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/17 22:09:35 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	setup_julia(void)
{
	t_fractal	j;

	j.zoom = 1;
	j.julia = 1;
	j.burning = 0;
	j.x_cent = 0.0;
	j.y_cent = 0.0;
	j.x_wid = 4.0;
	j.y_wid = 4.0;
	return (j);
}

t_fractal	setup_mandelbrot(void)
{
	t_fractal	m;

	m.zoom = 1;
	m.julia = 0;
	m.burning = 0;
	m.x_cent = -0.5;
	m.y_cent = 0.0;
	m.x_wid = 3.5;
	m.y_wid = 2.5;
	return (m);
}

t_fractal	setup_burningship(void)
{
	t_fractal	b;

	b.zoom = 1;
	b.julia = 0;
	b.burning = 1;
	b.x_cent = -0.5;
	b.y_cent = -0.25;
	b.x_wid = 3.0;
	b.y_wid = 3.0;
	return (b);
}

int			setup_fractal(t_image *img, char *fract_arg)
{
	if (ft_strcmp(fract_arg, "mandelbrot") == 0)
	{
		img->fract_funct = &mandelbrot;
		img->fractal = setup_mandelbrot();
		return (1);
	}
	if (ft_strcmp(fract_arg, "julia") == 0)
	{
		img->fract_funct = &julia;
		img->fractal = setup_julia();
		return (1);
	}
	if (ft_strcmp(fract_arg, "burningship") == 0)
	{
		img->fract_funct = &mandelbrot;
		img->fractal = setup_burningship();
		return (1);
	}
	return (0);
}
