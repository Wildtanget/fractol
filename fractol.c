#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;

    check_arguments(argc, argv, &fractal);
    init_fractal(&fractal);
    render(&fractal);
    mlx_hook(fractal.win_ptr, DestroyNotify, 0, (void *)close_program, &fractal);
    mlx_key_hook(fractal.win_ptr, keyhook, &fractal);
    mlx_mouse_hook(fractal.win_ptr, mousehook, &fractal);
    mlx_loop(fractal.mlx_ptr);
    return (0);
}

void check_arguments(int argc, char **argv, t_fractal *fractal)
{
    if (argc == 1)
    {
        printf("Please specify a set.\nUsage: ./a.out \"set\"\n");
        exit(1);
    }
    else if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
        fractal->set = MANDELBROT;
    else if (ft_strncmp(argv[1], "julia", 5) == 0)
        fractal->set = JULIA;
    else if (ft_strncmp(argv[1], "burning_ship", 12) == 0)
        fractal->set = BURNING_SHIP;
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

void    init_fractal(t_fractal *fractal)
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
    fractal->offset_x = 0;
    fractal->offset_y = 0;
    fractal->scale = 1;
    fractal->iterations = 40;
    fractal->color.r = 255;
    fractal->color.g = 0;
    fractal->color.b = 0;
}

void render(t_fractal *fractal)
{
    double x;
    double y;
    t_complex temp;
    int escape_num;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            temp.x = (map(x, -2, +2, 0, WIDTH) * fractal->scale) + fractal->offset_x;
            temp.y = (map(y, +2, -2, 0, HEIGHT) * fractal->scale) - fractal->offset_y;
            if (fractal->set == MANDELBROT)
                escape_num = iterater(temp, fractal);
            if (escape_num < fractal->iterations)
                place_pixel(fractal, x, y, scale_color(escape_num, fractal));
            else
                place_pixel(fractal, x, y, 0x000000);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img.img, 0, 0);
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

int iterater(t_complex c, t_fractal *fractal)
{
    int i = 0;
    t_complex z;
    z.x = 0.0;
    z.y = 0.0;

    while (i < fractal->iterations)
    {
        z = sum_complex(square_complex(z), c);
        if ((z.x * z.x) + (z.y * z.y) > 4)
            return (i);
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
    // printf("%d was pressed\n", keycode);
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
    else if (keycode == XK_minus)
        fractal->iterations -= 10;
    else if (keycode == XK_equal)
        fractal->iterations += 10;
    else if (keycode >= XK_1 && keycode <= XK_9)
        shift_color(keycode, fractal);
    render(fractal);
    return (0);
}

int mousehook(int button, int x, int y, t_fractal *fractal)
{
    // printf("%d was pressed at (%d, %d)\n", button, x, y);
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

int scale_color(int escape_num, t_fractal *fractal) {
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