/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:13:05 by pvong             #+#    #+#             */
/*   Updated: 2023/01/13 18:50:45 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../mlx_opengl/mlx.h"
# include "./x11events.h"
# include "./key_macos.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct s_fractol {
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			red_burningship;
	int			julia_mouse;
	double		x;
	double		y;
	int			it;
	int			it_max;
	int			show_text;
	int			show_help;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_fractol;

/* Init window & Init fractol*/
void	mlx_win_init(t_fractol *data);
int		correct_fractol(char **entered_fract, t_fractol *data);
void	init_fract(t_fractol *data);

/* Hook */
void	hook(t_fractol *data);
int		control_key(int keycode, t_fractol *data);
int		expose_hook(t_fractol *data);

/* keyhook */
int		key_hook3(int keycode, t_fractol *data);
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

/* Julia */
int		mouse_julia(int x, int y, t_fractol *data);
void	julia_init(t_fractol *data);
void	julia_calc(t_fractol *data);
void	julia(t_fractol *data);

/* Burningship */
void	burningship_init(t_fractol *data);
void	burningship(t_fractol	*data);
void	burningship_calc(t_fractol *data);

/* Utils */
int		ft_close(void);
void	put_text(t_fractol *data);
void	put_text2(t_fractol *data);
void	put_text3(t_fractol *data);
void	ft_strdel(char **as);

/* mlx */
void	put_pxl_to_img(t_fractol *data, int x, int y, int color);

#endif