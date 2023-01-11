/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:19:41 by pvong             #+#    #+#             */
/*   Updated: 2023/01/11 20:10:54 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4, \
			&color, sizeof(int));
	}
}

int	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot(data);
	if (data->fract == 1)
		julia(data);
	if (data->fract == 2)
		burningship(data);
	if (data->show_text)
	{
		put_text(data);
		put_text2(data);
	}
	if (data->show_help)
		put_text3(data);
	return (0);
}

/* Initialize our mlx, the window and the image */
void	mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_ptr = mlx_get_data_addr(data->img, \
				&data->bpp, &data->sl, &data->endian);
}

/* Close the window by exiting */
int		ft_close(void)
{
	exit(1);
	return (0);
}