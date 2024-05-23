/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:31:22 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/21 18:01:06 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	start_hooks(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, DestroyNotify, 0,
		(void *)close_program, fractal);
	mlx_key_hook(fractal->win_ptr, keyhook, fractal);
	mlx_mouse_hook(fractal->win_ptr, mousehook, fractal);
}

int	keyhook(int keycode, t_fractal *fractal)
{
	if (keycode == XK_Escape)
		close_program(fractal);
	else if (keycode == XK_Left || keycode == XK_a)
		fractal->offset_x -= (.5 * fractal->scale);
	else if (keycode == XK_Right || keycode == XK_d)
		fractal->offset_x += (.5 * fractal->scale);
	else if (keycode == XK_Up || keycode == XK_w)
		fractal->offset_y -= (.5 * fractal->scale);
	else if (keycode == XK_Down || keycode == XK_s)
		fractal->offset_y += (.5 * fractal->scale);
	else if (keycode == XK_o)
		fractal->iterations -= 10;
	else if (keycode == XK_i)
		fractal->iterations += 10;
	else if (keycode >= XK_1 && keycode <= XK_9)
		shift_color(keycode, fractal);
	else if (keycode == XK_r)
		reset(fractal);
	render(fractal);
	return (0);
}

int	mousehook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 4 && x && y)
	{
		fractal->scale *= 0.9;
		fractal->offset_x += (scale_map(x, -2, 2, WIDTH) * fractal->scale) / 8;
		fractal->offset_y += (scale_map(y, -2, 2, HEIGHT) * fractal->scale) / 8;
	}
	else if (button == 5)
	{
		fractal->scale *= 1.1;
		fractal->offset_x -= (scale_map(x, -2, 2, WIDTH) * fractal->scale) / 8;
		fractal->offset_y -= (scale_map(y, -2, 2, HEIGHT) * fractal->scale) / 8;
	}
	else if (button == 1 && fractal->set == JULIA)
	{
		fractal->julia.x = scale_map(x, -2, +2, WIDTH);
		fractal->julia.y = scale_map(y, +2, -2, HEIGHT);
	}
	render(fractal);
	return (0);
}
