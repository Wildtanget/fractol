#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;

    check_arguments(argc, argv, &fractal);
    init_fractal(argv, &fractal);
    render(&fractal);
    mlx_hook(fractal.win_ptr, DestroyNotify, 0, (void *)close_program, &fractal);
    mlx_key_hook(fractal.win_ptr, keyhook, &fractal);
    mlx_mouse_hook(fractal.win_ptr, mousehook, &fractal);
    mlx_loop(fractal.mlx_ptr);
    return (0);
}

void check_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && argc == 2)
        fractal->set = MANDELBROT;
    else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
        fractal->set = JULIA;
    else if (ft_strncmp(argv[1], "burning_ship", 12) == 0 && argc == 2)
        fractal->set = BURNING_SHIP;
	else
	{
		printf("Invalid arguments!\nUsage: ./a.out \"fractal\" [x] [y]\n");
        exit(1);
	}
}

int ft_strncmp(char *s1, char *s2, int length)
{
    if (s1 == NULL || NULL == s2 || length <= 0)
        return (1);
    while (*s1 == *s2 && length > 0)
    {
        s1++;
        s2++;
        length--;
    }
    return (*s1 - *s2);
}

void    init_fractal(char **argv, t_fractal *fractal)
{
    fractal->mlx_ptr = mlx_init();
    if (fractal->mlx_ptr == NULL)
        handle_error(1);
    fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "mandelbrot");
    if (fractal->win_ptr == NULL)
        handle_error(2);
    fractal->img.img = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
    if (fractal->img.img == NULL)
        handle_error(3);
    fractal->img.addr = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp, &fractal->img.len, &fractal->img.endian);
    if (fractal->img.addr == NULL)
        handle_error(4);
    reset(fractal);
	if (fractal->set == JULIA)
	{
		fractal->julia.x = ft_atod(argv[2]);
		fractal->julia.y = ft_atod(argv[3]);
	}
}

void render(t_fractal *fractal)
{
    double x;
    double y;
    t_complex temp;
    double escape_num;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            temp.x = (map(x, -2, +2, 0, WIDTH) * fractal->scale) + fractal->offset_x;
            temp.y = (map(y, 2, -2, 0, HEIGHT) * fractal->scale) - fractal->offset_y;
            if (fractal->set == MANDELBROT)
                escape_num = mandelbrot(temp, fractal);
            else if (fractal->set == BURNING_SHIP)
                escape_num = burning_ship(temp, fractal);
            else if (fractal->set == JULIA)
				escape_num = julia(temp, fractal);
            if (escape_num < fractal->iterations && (temp.x * temp.x) + (temp.y * temp.y) <= 4)
                place_pixel(fractal, x, y, scale_color(escape_num, fractal));
            else
                place_pixel(fractal, x, y, BLACK);
            y++;
        }
        x++;
    }

    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img, 0, 0);
	display_settings(fractal);
}

void place_pixel(t_fractal *fractal, int x, int y, int color)
{
    char *dst;

    dst = fractal->img.addr + (y * fractal->img.len + x * (fractal->img.bpp / 8));
	*(unsigned int*)dst = color;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}

t_complex square_complex(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}


t_complex square_complex_abs(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * fabs(z.x * z.y);
    return (result);
}

double mandelbrot(t_complex c, t_fractal *fractal)
{
    int i = 0;
    t_complex z;
	double	z_squared;
    z.x = 0.0;
    z.y = 0.0;

    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
		z_squared = (z.x * z.x) + (z.y * z.y);
        if ((z.x * z.x) + (z.y * z.y) > 4)
            return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
        i++;
    }
    return (fractal->iterations);
}

double burning_ship(t_complex c, t_fractal *fractal)
{
    int 		i = 0;
    t_complex 	z;
    z.x = 0.0;
    z.y = 0.0;
	double	z_squared;

    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex_abs(z), c);
		z_squared = (z.x * z.x) + (z.y * z.y);
        if ((z.x * z.x) + (z.y * z.y) > 4)
            return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
        i++;
    }
    return (fractal->iterations);
}

double julia(t_complex c, t_fractal *fractal)
{
    int i = 0;
    t_complex z;
	double	z_squared;
    z.x = c.x;
    z.y = c.y;

    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), fractal->julia);
		z_squared = (z.x * z.x) + (z.y * z.y);
        if ((z.x * z.x) + (z.y * z.y) > 4)
            return (i + 1 - log(log(sqrt(z_squared))) / log(2.0));
        i++;
    }
    return (fractal->iterations);
}

void close_program(t_fractal *fractal)
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

int keyhook(int keycode, t_fractal *fractal)
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

int mousehook(int button, int x, int y, t_fractal *fractal)
{
    if (button == 4 && x && y)
        fractal->scale *= 0.9;
    if (button == 5)
        fractal->scale *= 1.1;
    render(fractal);
    return (0);
}

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void handle_error(int code)
{
    printf("Failed with code: %d", code);
    exit(1);
}

int scale_color(double escape_num, t_fractal *fractal) {
    int hex_color;

    double t = (double)escape_num / fractal->iterations;
    int r = (int)(fractal->color.r * t);
    int g = (int)(fractal->color.g * t);
    int b = (int)(fractal->color.b * t);

    hex_color = r << 16 | g << 8 | b;
    return hex_color;
}

void shift_color(int keycode, t_fractal *fractal)
{
    if (keycode == XK_1)
        fractal->color = hex_to_rgb(NEON_GREEN);
    else if (keycode == XK_2)
        fractal->color = hex_to_rgb(ELECTRIC_BLUE);
    else if (keycode == XK_3)
        fractal->color = hex_to_rgb(HOT_PINK);
    else if (keycode == XK_4)
        fractal->color = hex_to_rgb(DEEP_PURPLE);
    else if (keycode == XK_5)
        fractal->color = hex_to_rgb(ACID_YELLOW);
    else if (keycode == XK_6)
        fractal->color = hex_to_rgb(FIERY_ORANGE);
    else if (keycode == XK_7)
        fractal->color = hex_to_rgb(TURQUOISE);
    else if (keycode == XK_8)
        fractal->color = hex_to_rgb(CRIMSON_RED);
    else if (keycode == XK_9)
        fractal->color = hex_to_rgb(ROYAL_BLUE);
}

t_rgb hex_to_rgb(int hex)
{
    t_rgb color;

    color.r = (hex >> 16) & 0xFF;
    color.g = (hex >> 8) & 0xFF;
    color.b = hex & 0xFF;
    return (color);
}

void reset(t_fractal *fractal)
{
	fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->scale = 1;
    fractal->iterations = 40;
    fractal->color.r = 255;
    fractal->color.g = 255;
    fractal->color.b = 255;
}

void display_settings(t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.10, HEIGHT * 0.08, WHITE, "SETINGS");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04, HEIGHT * 0.12, WHITE, "R            => RESET");
    mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04, HEIGHT * 0.14, WHITE, "W/A/S/D      => MOVE");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04, HEIGHT * 0.16, WHITE, "I/O          => CHANGE ITERATIONS");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04, HEIGHT * 0.18, WHITE, "1-9          => CHANGE COLOR");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, WIDTH * 0.04, HEIGHT * 0.20, WHITE, "SCROLL WHEEL => ZOOM IN/OUT");
}

double ft_atod(char *str)
{
	double	left;
	double	right;
	int		sign;
	double	factor;

	sign = 1;
	left = 0;
	right = 0;
	factor = 10;
	while (*str == ' ' || *str == '+')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		left = left * 10 + *str - 48;
		str++;
	}
	if (*str == '.')
		str++;
	while (*str)
	{
		right = right + (*str - 48) / factor;
		factor = factor * 10;
		str++;
	}
	return ((left + right) * sign);
}