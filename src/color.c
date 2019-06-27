/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:29:42 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/17 20:44:31 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define P1 0.00
#define P2 (2 * M_PI) / 3
#define P3 (4 * M_PI) / 3

void	init_color_struct(t_image *img)
{
	img->color.cent = 127;
	img->color.wid = 128;
	img->color.r_freq = 0.33;
	img->color.g_freq = 0.33;
	img->color.b_freq = 0.33;
	img->color.r_phase = 0.00;
	img->color.g_phase = (2 * M_PI) / 3;
	img->color.b_phase = (4 * M_PI) / 3;
}

void	change_col_freq(t_color *col, double r, double g, double b)
{
	col->r_freq = r;
	col->g_freq = g;
	col->b_freq = b;
}

void	change_col_phase(t_color *col, double r, double g, double b)
{
	col->r_phase = r;
	col->g_phase = g;
	col->b_phase = b;
}

void	select_color_palette(int key, t_image *img)
{
	if (key == 29)
		init_color_struct(img);
	if (key == 18)
	{
		change_col_freq(&img->color, 0.00, 0.33, 0.33);
		change_col_phase(&img->color, P2, P1, P3);
	}
	if (key == 19)
	{
		change_col_freq(&img->color, 0.166, 0.00, 0.33);
		change_col_phase(&img->color, P3, P1, P2);
	}
	if (key == 20)
	{
		change_col_freq(&img->color, 0.33, 0.33, 0.00);
		change_col_phase(&img->color, P2, P3, P1);
	}
	img->color.cent = (key == 21) ? 200 : img->color.cent;
	img->color.wid = (key == 21) ? 55 : img->color.cent;
	if (key == 23)
		change_col_freq(&img->color, 0.33, 0.66, 0.99);
	if (key == 22)
		change_col_phase(&img->color, P1, P1, P1);
}

int		make_color(t_image *img, double iterations)
{
	int		r;
	int		g;
	int		b;
	t_color	c;

	c = img->color;
	if (iterations >= img->max_iter)
		return (0);
	else
	{
		r = sin(c.r_freq * iterations + c.r_phase) * c.wid + c.cent;
		g = sin(c.g_freq * iterations + c.g_phase) * c.wid + c.cent;
		b = sin(c.b_freq * iterations + c.b_phase) * c.wid + c.cent;
		return (r << 16 | g << 8 | b);
	}
}
