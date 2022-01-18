/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:39:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 23:46:25 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int mandelbrot(t_fractol *frac)
{
	int	i;

	i = calc_mandelbrot(frac, frac->axis, frac->z, frac->c);

	return (i);
}

int	calc_mandelbrot(t_fractol *frac, t_axis *axis, t_z *z, t_c *c)
{
	int	i;
	double	temp;

	i = -1;
	c->r = axis->x;
	c->i = axis->y;
	while(++i < frac->loop_max)
	{
		temp = z->r;
		z->r = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * temp * z->i + c->i;
		if ((z->r * z->r) + (z->i * z->i) > 4.0)
			break; 
	}
	return (i);
}