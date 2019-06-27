/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:39:52 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/18 16:08:46 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITERATIONS 50
# define WIDTH 800
# define HEIGHT 600
# define IMG_WIDTH 800
# define IMG_HEIGHT 600
# define TOTAL_RANGES 4
# define WIN_NAME "42 Fractol"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_complex
{
	double		r;
	double		i;
	double		old_r;
}				t_complex;

typedef struct	s_color
{
	int			cent;
	int			wid;
	double		r_freq;
	double		g_freq;
	double		b_freq;
	double		r_phase;
	double		g_phase;
	double		b_phase;
}				t_color;

typedef struct	s_mouse
{
	double		x;
	double		y;
	double		x_ratio;
	double		y_ratio;
	int			freeze;
}				t_mouse;

typedef struct	s_fractal
{
	int			x;
	int			y;
	int			julia;
	int			burning;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		old_z_r;
	double		zoom;
	double		x_wid;
	double		x_cent;
	double		x_min;
	double		x_max;
	double		y_cent;
	double		y_wid;
	double		y_min;
	double		y_max;
	t_complex	z;
	t_complex	c;
}				t_fractal;

typedef void	(*t_fract_ft)(void *img, int pix_index);

typedef struct	s_image
{
	void		*ptr;
	char		*addr;
	double		*smooth;
	double		x_off;
	double		y_off;
	int			bpp;
	int			size;
	int			endian;
	pthread_t	tids[4];
	int			mouse_x;
	int			mouse_y;
	int			max_iter;
	t_fract_ft	fract_funct;
	t_fractal	fractal;
	t_color		color;
	t_mouse		mouse;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		*img;
	t_image		*copy;
}				t_mlx;

typedef struct	s_args
{
	t_image		*img;
	int			quad;
}				t_args;

double			interp(double start, double end, double percent);
void			draw_fractol(t_mlx *mlx);
void			image_set_pixel(t_image *img, int x, int y, int color);
void			init_color_struct(t_image *img);
void			mandelbrot(void *img, int pix_index);
void			julia(void *img, int pix_index);
void			select_color_palette(int key, t_image *img);
int				make_color(t_image *img, double iterations);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_moved(int x, int y, t_mlx *mlx);
int				key_press(int key, t_mlx *mlx);
int				keydown(int key, t_mlx *mlx);
int				get_pixel_index(int row, int col, int width);
int				setup_fractal(t_image *img, char *fractal_arg);
int				window_close(t_mlx *mlx);
t_fractal		get_fract_min_max(t_image *img, t_fractal f);
t_image			*image_init(t_mlx *mlx, char *arg);
t_mouse			init_mouse(void);

#endif
