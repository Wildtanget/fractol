/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 03:55:38 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/23 03:55:38 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	display_settings(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.10,
		HEIGHT * 0.08, WHITE, "SETINGS");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.12, WHITE, "R            => RESET");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.14, WHITE, "W/A/S/D      => MOVE");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.16, WHITE, "I/O          => CHANGE ITERATIONS");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.18, WHITE, "1-9          => CHANGE COLOR");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.20, WHITE, "SCROLL WHEEL => ZOOM IN/OUT");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04,
		HEIGHT * 0.22, WHITE, "LEFT CLICK   => CHANGE JULIA");
}

void	print_settings(void)
{
	ft_printf("%sKeyboard controls%s\n", A_BOLD, A_RESET);
	ft_printf("  R 		=>	Reset all values\n");
	ft_printf("  W 		=>	Move up\n");
	ft_printf("  S 		=>	Move down\n");
	ft_printf("  A 		=>	Move left\n");
	ft_printf("  D 		=>	Move right\n");
	ft_printf("  I 		=>	Zoom in\n");
	ft_printf("  O		=>	Zoom out\n");
	ft_printf("  1-9		=>	Change color\n");
	ft_printf("  ESC		=>	Close program\n\n");
	ft_printf("%sMouse controls%s\n", A_BOLD, A_RESET);
	ft_printf("  Scroll wheel	=>	Zoom in or out\n");
	ft_printf("  Left click	=>	Change argument for Julia fractal\n");
}
