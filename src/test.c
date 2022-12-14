/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:45:08 by pvong             #+#    #+#             */
/*   Updated: 2022/12/14 15:35:37 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_opengl/mlx.h"
#include "../include/test.h"
#include "../libft/libft.h"

// https://github.com/Ma3ert/fract-ol-42
// https://github.com/GlThibault/Fractol
// https://codeberg.org/Vusk/fractol/src/branch/master/src/fractol.c
// Check https://mathworld.wolfram.com/MandelbrotSet.html
// http://www.fractalsciencekit.com/program/maneqn.htm
// For more informations on fractals
// (a + ib)^2 = a^2 - b^2 + 2abi 
// 		with a^2 - b^2 being the real 
//		and 2abi the imaginary part
// z = z^2 + c  with z being a complex number
// 		Z_real = Z_real^2 - Z_imaginary^2 + c_real
// 		Z_imaginary = 2 * Z_real * Z_imaginary + c_imaginary

/* Put a pixel on the frame
pixel = data->addr + (y * data->line_length + x * data->bits_per_pixel / 8); */

int	main()
{
	t_fractol *data;

	data  = malloc(sizeof(t_fractol));
	if (!data)
		return (0);
	mlx_win_init(data);
	data->fract = 0;
	mandelbrot_init(data);
	// fract_calc(data);
	mlx_hook(data->win, KEY_PRESS, KEY_PRESS_MASK, )
	mlx_loop(data->mlx);
	return (0);
}