/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:54:29 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:09:26 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol_bonus.h"

void	init_fractal(char **argv, t_fractal *fractal)
{
	fractal->mlx_ptr = NULL;
	fractal->win_ptr = NULL;
	fractal->img.img = NULL;
	fractal->img.addr = NULL;
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		handle_error(fractal, "Failed initializing mlx");
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, "mandelbrot");
	if (fractal->win_ptr == NULL)
		handle_error(fractal, "Failed creating a new window");
	fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (fractal->img.img == NULL)
		handle_error(fractal, "Failed creating a new image");
	fractal->img.addr = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp, &fractal->img.len, &fractal->img.endian);
	if (fractal->img.addr == NULL)
		handle_error(fractal, "Failed getting an image address");
	reset(fractal);
	if (fractal->set == JULIA)
	{
		fractal->julia.x = ft_atod(argv[2]);
		fractal->julia.y = ft_atod(argv[3]);
	}
}

void	reset(t_fractal *fractal)
{
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->scale = 1;
	fractal->iterations = 40;
	fractal->color.r = 255;
	fractal->color.g = 255;
	fractal->color.b = 255;
}
