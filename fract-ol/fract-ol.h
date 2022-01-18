/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:34:24 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 20:15:10 by seungsle         ###   ########.fr       */
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

# define IMG_WIDTH 800
# define IMG_HEIGHT 800

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct	s_fractol
{
	int		(*function)(struct s_fractol *);
	t_img		img;
	t_mlx		*mlx;
}				t_fractol;

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void free_exit(t_fractol *frac);
int check_valid(int argc, char **argv, t_fractol *frac);
void draw(t_fractol *frac);
void fractol(t_fractol *frac);

int julia(t_fractol *frac);
int mandelbrot(t_fractol *frac);

#endif