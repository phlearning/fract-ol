/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:45:08 by pvong             #+#    #+#             */
/*   Updated: 2023/01/10 14:26:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_opengl/mlx.h"
#include "../include/fractol.h"
#include "../libft/libft.h"

void	init_fract(t_fractol *data)
{
	if (data->fract == 0)
		mandelbrot_init(data);
	if (data->fract == 1)
		julia_init(data);
	fract_calc(data);
}

int correct_fractol(char **entered_fract, t_fractol *data)
{
	if (ft_strcmp(entered_fract[1], "Mandelbrot") == 0 \
	|| ft_strcmp(entered_fract[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(entered_fract[1], "Julia") == 0 \
		|| ft_strcmp(entered_fract[1], "julia") == 0)
		data->fract = 1;
	else
	{
		ft_printf("Possible fractol Mandelbrot or Julia. Ex: ./fractol Mandelbrot\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol *data;

	data  = malloc(sizeof(t_fractol));
	if (!data)
		return (0);
	if (ac == 2)
	{
		mlx_win_init(data);
		if (correct_fractol(av, data) == 0)
			return (0);
		init_fract(data);
		mlx_hook(data->win, MOTION_NOTIFY, POINTER_MOTION_MASK, mouse_julia, data);
		mlx_expose_hook(data->win, expose_hook, data);
		mlx_loop_hook(data->mlx, fract_calc, data);
		mlx_hook(data->win, DESTROY_NOTIFY, 0L, ft_close, data);
		mlx_key_hook(data->win, control_key, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
	}
	else
		ft_printf("\tChoose between Mandelbrot or Julia: ex ./fractol mandelbrot \n\
		\t\t\t\t./fractol julia\n");
	return (0);
}