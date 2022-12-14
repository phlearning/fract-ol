/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:38:01 by pvong             #+#    #+#             */
/*   Updated: 2022/12/14 15:46:35 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	key_event(int keycode, t_fractol *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->color);
		free(data->img);
		free(data);
		exit(0);
	}
	if (keycode == K_SP)
		mandelbrot_init(data);
	handle_key_event(keycode, data);
	lighting_pixels_man(data);
	return (0);
}