/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:02:17 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/13 19:09:36 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractal *fractal)
{
	double		x;
	double		y;
	t_complex	temp;
	double		escape_num;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			temp.x = (scale_map(x, -2, +2, WIDTH)
					* fractal->scale) + fractal->offset_x;
			temp.y = (scale_map(y, 2, -2, HEIGHT)
					* fractal->scale) - fractal->offset_y;
			if (fractal->set == MANDELBROT)
				escape_num = mandelbrot(temp, fractal);
			else if (fractal->set == BURNING_SHIP)
				escape_num = burning_ship(temp, fractal);
			else if (fractal->set == JULIA)
				escape_num = julia(temp, fractal);
			if (escape_num < fractal->iterations
				&& (temp.x * temp.x) + (temp.y * temp.y) <= 4)
				place_pixel(fractal, x, y, scale_color(escape_num, fractal));
			else
				place_pixel(fractal, x, y, BLACK);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr,
		fractal->win_ptr, fractal->img.img, 0, 0);
	display_settings(fractal);
}

void	place_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->img.addr
		+ (y * fractal->img.len + x * (fractal->img.bpp / 8));
	*(unsigned int *)dst = color;
}

double	scale_map(double x, double y_mn, double y_mx, double x_mx)
{
	double	result;
	double	x_mn;

	x_mn = 0;
	result = (x - x_mn) * (y_mx - y_mn);
	result /= (x_mx - x_mn);
	result += y_mn;
	return (result);
}
