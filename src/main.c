/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:45:08 by pvong             #+#    #+#             */
/*   Updated: 2023/01/15 19:48:24 by pvong            ###   ########.fr       */
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
	if (data->fract == 2)
		burningship_init(data);
	fract_calc(data);
}

int	correct_fractol(char **entered_fract, t_fractol *data)
{
	data->show_help = 1;
	if (ft_strcmp(entered_fract[1], "Mandelbrot") == 0 \
	|| ft_strcmp(entered_fract[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(entered_fract[1], "Julia") == 0 \
		|| ft_strcmp(entered_fract[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(entered_fract[1], "Burningship") == 0 \
		|| ft_strcmp(entered_fract[1], "burningship") == 0)
		data->fract = 2;
	else
	{
		ft_printf("Possible fractol Mandelbrot, Julia or Burningship.");
		ft_printf(" Ex: ./fractol Mandelbrot\n");
		data = 0;
		free(data);
		return (0);
	}
	return (1);
}

void	hook(t_fractol *data)
{
	mlx_hook(data->win, MOTION_NOTIFY, 0, mouse_julia, data);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_loop_hook(data->mlx, fract_calc, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, ft_close, data);
	mlx_key_hook(data->win, control_key, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_fractol	*data;

	data = malloc(sizeof(t_fractol));
	if (!data)
		return (0);
	if (ac == 2)
	{
		if (correct_fractol(av, data) == 0)
		{
			free(data);
			return (0);
		}
		mlx_win_init(data);
		init_fract(data);
		hook(data);
	}
	else
	{
		ft_printf("\tChoose between Mandelbrot, Julia or Burningship: ");
		ft_printf("ex ./fractol mandelbrot\n");
	}
	free(data);
	return (0);
}
