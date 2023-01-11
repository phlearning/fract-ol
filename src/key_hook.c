/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:38:01 by pvong             #+#    #+#             */
/*   Updated: 2023/01/11 20:08:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		expose_hook(t_fractol *data)
{
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp, \
	&data->sl, &data->endian);
	fract_calc(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int		key_hook3(int keycode, t_fractol *data)
{
	if (keycode == K_LSHIFT)
	{
		data->fract = (data->fract + 1) % 3;
		init_fract(data);
	}
	return (0);
}

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == K_NUM_2)
	{
		data->color = 2050;
		data->red_burningship = -1;
	}
	else if (keycode == K_NUM_3)
	{
		data->color = 265;
		data->red_burningship = -1;
	}
	else if (keycode == K_NUM_4)
	{
		data->red_burningship = !data->red_burningship;
		data->color = 16711680;
	}
	else if (keycode == K_P)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == K_I)
		data->show_text = !data->show_text;
	else if (keycode == K_H)
		data->show_help= !data->show_help;
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == K_NP_PLU)
		data->it_max += 10;
	else if (keycode == K_NP_MIN)
		data->it_max -= 10;
	else if (keycode == K_AR_L)
		data->x1 -= 30 / data->zoom;
	else if (keycode == K_AR_R) 
		data->x1 += 30 / data->zoom;
	else if (keycode == K_AR_D)
		data->y1 += 30 / data->zoom;
	else if (keycode == K_AR_U)
		data->y1 -= 30 / data->zoom;
	else if (keycode == K_SP)
		init_fract(data);
	else if (keycode == K_NUM_1)
	{
		data->color = 1077216;
		data->red_burningship = -1;
	}
	key_hook2(keycode, data);
	key_hook3(keycode, data);
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