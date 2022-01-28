/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:39:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 15:57:58 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	mandelbrot(t_fractol *frac, t_axis *axis, t_z *z, t_c *c)
{
	int	i;
	double	temp;

	i = -1;
	// if (frac->center[0] != 0)
	// 	frac->center[0] /= frac->zoom;
	// else if (frac->center[1] != 0)
	// 	frac->center[1] /= frac->zoom;
	frac->curr[0] = 0;
	frac->curr[1] = 0;
	calc_axis(axis->x, axis->y, frac);
	c->r = ((frac->curr[0] - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);//+  frac->center[0];
	c->i = ((WIN_HEIGHT / 2) - frac->curr[1]) * (4.0) / WIN_HEIGHT;// + frac->center[1];
	z->r = 0;
	z->i = 0;
	while(++i < frac->loop_max)
	{
		temp = z->r;
		z->r = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * temp * z->i + c->i;
		if ((z->r * z->r) + (z->i * z->i) > 4)
			break;
	}
	return (i);
}
