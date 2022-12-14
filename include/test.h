/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:13:05 by pvong             #+#    #+#             */
/*   Updated: 2022/12/14 14:11:18 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx_opengl/mlx.h"

# define WIDTH 600
# define HEIGHT 600
# define THREAD_WIDTH 10
# define THREAD_NUMBER 300

typedef struct	s_fractol {
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_fractol;

/* Init window */
void	mlx_win_init(t_fractol *data);

/* Hook */
int		control_key(int keycode, t_fractol *data);
int		expose_hook(t_fractol *data);

/* keyhook */
int		key_hook2(int keycode, t_fractol *data);
int		key_hook(int keycode, t_fractol *data);

/* Mousehook */
void	ft_zoom(int x, int y, t_fractol *data);
void	ft_dezoom(int x, int y, t_fractol *data);
int		mouse_hook(int mousecode, int x, int y, t_fractol *data);

/* Mandelbrot */
void	mandelbrot_init(t_fractol *data);
int		fract_calc(t_fractol *data);
void	mandelbrot_calc(t_fractol *data);
void	mandelbrot(t_fractol *data);

/* Utils */
int		ft_close(void);
void	put_text(t_fractol *data);
void	ft_strdel(char **as);

/* mlx */
void	put_pxl_to_img(t_fractol *data, int x, int y, int color);

#endif