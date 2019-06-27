/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:34:28 by dpeck             #+#    #+#             */
/*   Updated: 2018/12/18 15:29:26 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		ft_putendl("error: bad argument");
		return (1);
	}
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, WIN_NAME);
	mlx->img = image_init(mlx, argv[1]);
	if (mlx->img == NULL)
	{
		ft_putendl("error: bad argument");
		return (1);
	}
	draw_fractol(mlx);
	mlx_key_hook(mlx->win_ptr, keydown, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, key_press, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_moved, mlx);
	mlx_hook(mlx->win_ptr, 17, 1L << 17, window_close, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
