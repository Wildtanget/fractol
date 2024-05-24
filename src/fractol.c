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

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (check_arguments(argc, argv, &fractal) == 1)
		return (EXIT_FAILURE);
	start_message(&fractal);
	init_fractal(argv, &fractal);
	render(&fractal);
	start_hooks(&fractal);
	print_settings();
	mlx_loop(fractal.mlx_ptr);
	return (0);
}

void	close_program(t_fractal *fractal)
{
	if (fractal->img.addr != NULL)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	if (fractal->win_ptr != NULL)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr != NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	exit(0);
}

void	handle_error(t_fractal *fractal, char *error)
{
	ft_printf("%s%s%s\n", A_RED, error, A_RESET);
	perror("Error");
	if (fractal->img.addr)
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img);
	if (fractal->win_ptr)
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	if (fractal->mlx_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	exit(1);
}

void	start_message(t_fractal *fractal)
{
	char	*set;
	char	*line;

	line = "=============================================================";
	if (fractal->set == 1)
		set = "mandelbrot";
	else if (fractal->set == 2)
		set = "julia";
	else if (fractal->set == 3)
		set = "burning ship";
	ft_printf("%s%s%s\n", A_CYAN, line, A_RESET);
	ft_printf("%s\t\tWelcome to Fractol - %s!%s\n", A_GREEN, set, A_RESET);
	ft_printf("%s%s%s\n", A_CYAN, line, A_RESET);
}
