/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:06:06 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 16:31:45 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "./mlx/mlx.h"
#include <math.h>
#include <stdlib.h>

#define	MALLOC_ERROR -1
#define MANY_PARAM_ERROR -2
#define INVALID_PARAM_ERROR -3

typedef struct	s_data
{
	int	(*function)(struct s_data *data);
}				t_data;

void	ft_putstr_fd(char *s, int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	mandelbrot(t_data *data);
int	julia(t_data *data);

#endif
