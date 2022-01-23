/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:39:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 23:49:28 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	mandelbrot(t_fractol *frac, t_axis *axis, t_z *z, t_c *c)
{
	int	i;
	double	temp;

	i = -1;
	if (frac->center[0] != 0)
		frac->center[0] /= frac->zoom;
	else if (frac->center[1] != 0)
		frac->center[1] /= frac->zoom;
	c->r = ((axis->x - WIN_WIDTH / 2) * (4.0 / frac->zoom) / WIN_WIDTH) + frac->center[0];
	c->i = ((WIN_HEIGHT / 2) - axis->y) * (4.0 / frac->zoom) / WIN_HEIGHT + frac->center[1];
	z->r = 0;
	z->i = 0;
	while(++i < frac->loop_max * frac->zoom)
	{
		temp = z->r;
		z->r = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * temp * z->i + c->i;
		if ((z->r * z->r) + (z->i * z->i) > 4)
			break;
	}
	return (i);
}
