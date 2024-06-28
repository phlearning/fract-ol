/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:09:45 by pvong             #+#    #+#             */
/*   Updated: 2024/06/28 14:56:41 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_julia(int x, int y, t_fractol *data)
{
	static int	prev_x = -1;
	static int	prev_y = -1;
	int	threshold;
	
	threshold = 10;
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		if (abs(x - prev_x) > threshold || abs(y - prev_y) > threshold)
		{
			data->c_r = x;
			data->c_i = y;
			mlx_destroy_image(data->mlx, data->img);
			mlx_clear_window(data->mlx, data->win);
			expose_hook(data);
			prev_x = x;
			prev_y = y;
		}
	}
	return (0);
}

/*init the variables (it_max / zoom_value / offset / color / complex / mouse)*/
void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.25;
	data->y1 = -2.25;
	data->color = 265;
	data->c_i = 465;
	data->c_r = 465;
	data->julia_mouse = 1;
}

/**
 * The scaling are done in the calculation, it would have better to do
 * the scaling beforehand.
 */
void	julia_calc(t_fractol *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && \
				data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i \
			- 0.5 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp - 0.5 + data->c_i / HEIGHT;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * (data->it % 20)));
}

void	julia(t_fractol *data)
{
	int	tmp;

	data->x = 0;
	data->y = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < HEIGHT)
		{
			julia_calc(data);
			data->y++;
		}
		data->x++;
	}
}
