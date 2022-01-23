/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:34:24 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 23:09:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "./mlx/mlx.h"
#include <math.h>
#include <stdlib.h>

# define TRUE 0
# define FALSE 1

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define SCROLL_UP	4
# define SCROLL_DOWN	5

typedef unsigned char un_char;

typedef struct	s_img
{
	void		*img_ptr;
	char		*data;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct	s_z
{
	double		r;
	double		i;
} 				t_z;

typedef struct	s_c
{
	double		r;
	double		i;
} 				t_c;

typedef struct	s_axis
{
	int			x;
	int			y;
}				t_axis;

typedef struct	s_clr
{
	un_char		r;
	un_char		g;
	un_char		b;
}				t_clr;

typedef struct	s_fractol
{
	int		(*function)(struct s_fractol *, t_axis *, t_z *, t_c *);
	double		loop_max;
	double		loop;
	double		zoom;
	double		center[2];
	t_clr		*clr;
	t_axis		*axis;
	t_z			*z;
	t_c			*c;
	t_img		*img;
	t_mlx		*mlx;
}				t_fractol;

void	input_cmp(char **argv, t_fractol *frac);
void	check_valid(int argc, char **argv, t_fractol *frac);
void	loop(t_fractol *frac);
void	fractol(t_fractol *frac);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	mandelbrot(t_fractol *frac, t_axis *axis, t_z *z, t_c *c);

int julia(t_fractol *frac, t_axis *axis, t_z *z, t_c *c);

void	free_exit_1(t_fractol *frac);
void	free_exit_2(t_fractol *frac);

void	init_sturct(t_fractol *frac);
void	init_mlx_struct(t_mlx *mlx);
void	init_img_struct(t_mlx *mlx, t_img *img);
void	init_zc_struct(t_z *z, t_c *c);
void	init_ax_clr_struct(t_axis *axis, t_clr * clr);

void	draw(t_fractol *frac);
void	get_color(t_fractol *frac, t_img *img, int x, int y);

int	mouse_scroll(int keycode, void *param);
int mouse_move(int x, int y, void *param);

int	listener(int keycode, void *param);

#endif