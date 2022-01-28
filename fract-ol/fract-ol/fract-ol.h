/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:06:06 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 18:49:34 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "./mlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define	DATA_MALLOC_ERROR -1
#define MANY_PARAM_ERROR -2
#define INVALID_PARAM_ERROR -3
#define MLX_MALLOC_ERROR -4
#define IMG_MALLOC_ERROR -5
#define RGB_MALLOC_ERROR -6
#define PXL_MALLOC_ERROR -7

# define SCROLL_UP	4
# define SCROLL_DOWN	5

#define WIN_WIDTH 800
#define WIN_HEIGHT 800

typedef unsigned char un_char;

typedef struct	s_pxl
{
	double		curr_zoom;
	double		last_zoom;
	double		curr[2];
	double		last[2];
}				t_pxl;

typedef struct	s_rgb
{
	un_char		r;
	un_char		g;
	un_char		b;
	int			set_r;
	int			set_g;
	int			set_b;
}				t_rgb;

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

typedef struct	s_data
{
	int			(*function)(struct s_data *data);
	t_img		*img;
	t_mlx		*mlx;
	t_rgb		*rgb;
	t_pxl		*pxl;
}				t_data;

void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	mandelbrot(t_data *data);
int	julia(t_data *data);

void error_detected(int error, t_data *data);
int	listener(int keycode, void *param);
int mouse_scroll(int button, int x, int y, void *param);

void	loop(t_data *data);
void calc_axis(int x, int y, t_pxl *pxl);

#endif
