/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:06:06 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 17:18:39 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define DATA_MALLOC_ERROR		-1
# define MANY_PARAM_ERROR		-2
# define INVALID_PARAM_ERROR	-3
# define MLX_MALLOC_ERROR		-4
# define IMG_MALLOC_ERROR		-5
# define RGB_MALLOC_ERROR		-6
# define PXL_MALLOC_ERROR		-7
# define ZC_MALLOC_ERROR		-8
# define AXIS_MALLOC_ERROR		-9

# define SCROLL_UP				4
# define SCROLL_DOWN			5

# define KEY_ESC				53

# define KEY_ONE				18
# define KEY_TWO				19
# define KEY_THREE				20

# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126

# define KEY_P					35
# define KEY_M					46

# define WIN_WIDTH				800
# define WIN_HEIGHT				800

typedef unsigned char			t_un_char;

typedef struct s_axis
{
	int			x;
	int			y;
}				t_axis;

typedef struct s_c
{
	double		r;
	double		i;
}				t_c;

typedef struct s_z
{
	double		r;
	double		i;
}				t_z;

typedef struct s_pxl
{
	double		curr_zoom;
	double		last_zoom;
	double		curr[2];
	double		last[2];
}				t_pxl;

typedef struct s_rgb
{
	int			set_r;
	int			set_g;
	int			set_b;
	t_un_char	r;
	t_un_char	g;
	t_un_char	b;
}				t_rgb;

typedef struct s_img
{
	void		*img_ptr;
	char		*data;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_data
{
	int			(*function)(struct s_data *, t_pxl *, int, int);
	int			loop_max;
	int			loop_mul;
	t_img		*img;
	t_mlx		*mlx;
	t_rgb		*rgb;
	t_pxl		*pxl;
	t_z			*z;
	t_c			*c;
	t_axis		*axis;
}				t_data;

void	check_valid(int argc, char **argv, t_data *data);

void	loop(t_data *data);
void	execute(t_data *data);

void	put_str(t_data *data);
int		mandelbrot(t_data *data, t_pxl *pxl, int x, int y);
int		julia(t_data *data, t_pxl *pxl, int x, int y);
int		burningship(t_data *data, t_pxl *pxl, int x, int y);

void	ft_putstr_fd(char *s, int fd);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	init_pxl(t_data *data);
void	init_rgb(t_data *data);
void	init_mlx(t_data *data);
void	init_img(t_data *data);
void	init(t_data *data);

void	init_zc(t_data *data);
void	init_axis(t_data *data);

int		listener(int keycode, void *param);

void	get_zoomed_center(int x, int y, t_pxl *pxl, t_data *data);
int		mouse_scroll(int button, int x, int y, void *param);

void	error_param(int error, t_data *data);
void	error_malloc(int error, t_data *data);
void	error_detected(int error, t_data *data);

void	calc_axis(int x, int y, t_pxl *pxl);
void	put_color(t_data *data, t_img *img, int x, int y);
void	pxl_to_img(t_data *data);

char	*ft_itoa(int n);

#endif
