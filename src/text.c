/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:25:49 by pvong             #+#    #+#             */
/*   Updated: 2023/01/11 20:08:14 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
	text = ft_strjoin("iter_max: ", nb);
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
	mlx_string_put(data->mlx, data->win, 10, 50, 0x4DACEE, \
	"PRESS H to hide help menu");
	mlx_string_put(data->mlx, data->win, 10, 70, 0xFFFFFF,\
	"PRESS the arrows to move");
	mlx_string_put(data->mlx, data->win, 10, 90, 0xFFFFFF, \
	"Click left on mouse or Scroll up to zoom");
	mlx_string_put(data->mlx, data->win, 10, 110, 0xFFFFFF, \
	"Click right on mouse or Scroll down to dezoom");
	mlx_string_put(data->mlx, data->win, 10, 130, 0xFFFFFF, \
	"Press I to check iter_max");
	mlx_string_put(data->mlx, data->win, 10, 150, 0xFFFFFF, \
	"Press P to pause mouse on Julia");
	mlx_string_put(data->mlx, data->win, 10, 170, 0xFFFFFF, \
	"Press + - to change iter_max");
	mlx_string_put(data->mlx, data->win, 10, 190, 0xFFFFFF, \
	"Press Shift to change fractals");
}