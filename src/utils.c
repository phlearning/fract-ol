/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:19:41 by pvong             #+#    #+#             */
/*   Updated: 2023/01/10 17:34:09 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	free(*as);
	*as = NULL;
}

void	put_text(t_fractol *data)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(data->it_max);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

void	put_text2(t_fractol *data)
{
	char	*text_cr;
	char	*text_ci;
	char	*nb_cr;
	char	*nb_ci;

	nb_cr = ft_itoa(data->c_r);
	nb_ci = ft_itoa(data->c_i);
	text_cr = ft_strjoin("nb_cr : ", nb_cr);
	text_ci = ft_strjoin("nb_ci : ", nb_ci);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, text_cr);
	mlx_string_put(data->mlx, data->win, 10, 30, 0xFFFFFF, text_ci);
	ft_strdel(&text_cr);
	ft_strdel(&text_ci);
	ft_strdel(&nb_cr);
	ft_strdel(&nb_ci);
}

void	put_text3(t_fractol *data)
{
	char	*text_color;
	char	*nb_color;

	nb_color = ft_itoa(data->color);
	text_color = ft_strjoin("color : ", nb_color);
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFFFFFF, text_color);
	ft_strdel(&text_color);
	ft_strdel(&nb_color);
}

int	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot(data);
	if (data->fract == 1)
		julia(data);
	if (data->show_text)
	{
		put_text(data);
		put_text2(data);
		put_text3(data);
	}	
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

/* c_r = x / zoom + x1; 
	c_r = x / zoom + (x / zoom + x1) - (x / zoom * 1.3) */
void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

/* c_r = x / zoom + x1; 
	c_r = x / zoom + (x / zoom + x1) - (x / zoom / 1.3) */
void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}