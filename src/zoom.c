/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:07:32 by pvong             #+#    #+#             */
/*   Updated: 2023/01/12 21:22:21 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/* The new x1 and y1 coordinates are computed by taking the current x1,y1 
and subtracting a fraction of the current zoom level, 
which cause the fractal to be centered on the point (x, y) that was clicked. */
void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = x / data->zoom - (x / (data->zoom * 1.3)) + data->x1;
	data->y1 = (y / data->zoom) - (y / (data->zoom * 1.3)) + data->y1;
	data->zoom *= 1.3;
	data->it_max += 2;
}

/* The ft_dezoom function does the opposite,
 it decrease the zoom level by dividing it by 1.3,
 and again adjust x1, y1 values,
 so the fractal is again centered on the point (x, y) that was clicked. */
void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max -= 2;
}
