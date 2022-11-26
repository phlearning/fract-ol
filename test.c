/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:45:08 by pvong             #+#    #+#             */
/*   Updated: 2022/11/26 18:39:08 by pvong            ###   ########.fr       */
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



/* For the display resolution*/
#define S_HEIGHT		900
#define S_WIDTH			1440
#define S_CENTER_H		S_HEIGHT/2
#define	S_CENTER_WIDTH	S_WIDTH/2

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
	img.img = mlx_new_image(mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int y = 150; y < 250; y++)
		for(int x = 150; x <= 250; x++)
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
