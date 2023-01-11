/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:48:19 by pvong             #+#    #+#             */
/*   Updated: 2023/01/11 18:39:50 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* init the variables (it_max / zoom_value / offset / color) */
void	mandelbrot_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = WIDTH / 3;
	data->x1 = -2.05;
	data->y1 = -1.5;
	data->color = 265;
}

/* navigate the screen and pass the x/y to our calc function */
void	mandelbrot(t_fractol	*data)
{
	int		tmp;

	data->x = 0;
	data->y = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < HEIGHT)
		{
			mandelbrot_calc(data);
			data->y++;
		}
		data->x++;
	}
}

/* transform the x/y into screen coord and put pixels.
	x1 and y1 are the offset
	the zoom value let us zoom in or zoom out
	but here it enables us to calculates the next complex */
void	mandelbrot_calc(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4 && \
				data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -	data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * (data->it % 20)));
}