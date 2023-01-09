/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:38:01 by pvong             #+#    #+#             */
/*   Updated: 2023/01/09 19:43:15 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		expose_hook(t_fractol *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, &data->sl, &data->endian);
	// mandelbrot(data);
	fract_calc(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 19) // Num 2
		data->color = 2050;
	else if (keycode == 20) // Num 3
		data->color = 265;
	else if (keycode == 35) // K_P
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 34) // K_I
		data->show_text = !data->show_text;
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69) // NUMPAD_+
		data->it_max += 10;
	else if (keycode == 78) // NUMPAD_-
		data->it_max -= 10;
	else if (keycode == 123) // LEFT_ARROW
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124) // RIGHT_ARROW
		data->x1 += 30 / data->zoom;
	else if (keycode == 125) // DOWN_ARROW
		data->y1 += 30 / data->zoom;
	else if (keycode == 126) // UP_ARROW
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49) // SPACE
		mandelbrot_init(data);
	else if (keycode == 18) // NUM_1
		data->color = 1677216;
	key_hook2(keycode, data);
	ft_printf("Key: %d\n", keycode);
	ft_printf("it_max = %d\n", data->it_max);
	return (0);
}

int	control_key(int keycode, t_fractol *data)
{
	int	r;

	r = 0;
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else
	{
		if (keycode >= 1 && keycode <= 258 && ++r > 0)
			key_hook(keycode, data);
		r++;
		if (r > 0)
		{
			mlx_destroy_image(data->mlx, data->img);
			mlx_clear_window(data->mlx, data->win);
			expose_hook(data);
		}
	}
	return (0);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1) // Scroll up or click
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2) // Scroll down or click
		ft_dezoom(x, y, data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	expose_hook(data);
	return (0);
}