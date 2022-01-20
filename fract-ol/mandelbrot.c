/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:39:38 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/20 13:33:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	mandelbrot(t_fractol *frac, t_axis *axis, t_z *z, t_c *c)
{
	int	i;
	double	temp;

	i = -1;
	c->r = -0.75;
	c->i = 0;
	z->r = ((axis->x - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	z->i = ((WIN_HEIGHT / 2) - axis->y) * 4.0 / WIN_HEIGHT;
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