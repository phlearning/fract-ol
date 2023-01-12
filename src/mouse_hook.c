/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:22:17 by pvong             #+#    #+#             */
/*   Updated: 2023/01/12 20:54:41 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Also mouse_julia in julia.c

int	mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == M_SCR_U || mousecode == M_CLK_L)
		ft_zoom(x, y, data);
	else if (mousecode == M_SCR_D || mousecode == M_CLK_R)
		ft_dezoom(x, y, data);
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	expose_hook(data);
	return (0);
}
