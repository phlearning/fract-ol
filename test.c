/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:45:08 by pvong             #+#    #+#             */
/*   Updated: 2022/12/05 18:48:01 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_opengl/mlx.h"
#include "test.h"

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*) pixel = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}