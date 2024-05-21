/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notahtah <notahtah@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:27:52 by notahtah          #+#    #+#             */
/*   Updated: 2024/05/21 20:21:51 by notahtah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	check_arguments(argc, argv, &fractal);
	init_fractal(argv, &fractal);
	render(&fractal);
	mlx_hook(fractal.win_ptr, DestroyNotify, 0,
		(void *)close_program, &fractal);
	mlx_key_hook(fractal.win_ptr, keyhook, &fractal);
	mlx_mouse_hook(fractal.win_ptr, mousehook, &fractal);
	print_settings();
	mlx_loop(fractal.mlx_ptr);
	return (0);
}

void	check_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
		fractal->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
		fractal->set = JULIA;
	else if (ft_strncmp(argv[1], "burning_ship", 12) == 0 && argc == 2)
		fractal->set = BURNING_SHIP;
	else
	{
		ft_printf("%sInvalid arguments!\n%s", A_RED, A_RESET);
		ft_printf("%sUsage:%s	./fractol mandelbrot\n%s", A_GRAY, A_ITA, A_RESET);
		ft_printf("%s%s	./fractol burning_ship\n%s", A_GRAY, A_ITA, A_RESET);
		ft_printf("%s%s	./fractol julia [x] [y]\n%s", A_GRAY, A_ITA, A_RESET);

		exit(1);
	}
}

void	close_program(t_fractal *fractal)
{
	if (fractal->img.addr != NULL)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	if (fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	exit(0);
}

void	handle_error(int code)
{
	ft_printf("Failed with code: %d", code);
	exit(1);
}

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
	ft_printf("  1-9		=>	Change color\n\n");
	ft_printf("%sMouse controls%s\n", A_BOLD, A_RESET);
	ft_printf("  Scroll wheel	=>	Zoom in or out\n");
	ft_printf("  Left click	=>	Change argument for Julia fractal\n");
}
