/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 20:08:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	mandelbrot(t_data *data, t_pxl *pxl, int x, int y)
{
	int i;
	double	temp;
	t_c		*c;
	t_z		*z;

	c = (t_c *)data->c;
	z = (t_z *)data->z;
	pxl->curr[0] = 0;
	pxl->curr[1] = 0;
	calc_axis(x, y, pxl);
	c->r = ((pxl->curr[0] - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);
	c->i = ((WIN_HEIGHT / 2) - pxl->curr[1]) * (4.0) / WIN_HEIGHT;
	z->r = 0;
	z->i = 0;
	while(++i < data->loop_max)
	{
		temp = z->r;
		z->r = (z->r * z->r) - (z->i * z->i) + c->r;
		z->i = 2 * temp * z->i + c->i;
		if ((z->r * z->r) + (z->i * z->i) > 4)
			break;
	}
	return (i);
}

int	julia(t_data *data, t_pxl *pxl, int x, int y)
{
	return (0);
}