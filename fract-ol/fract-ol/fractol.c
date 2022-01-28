/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 20:46:59 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	mandelbrot(t_data *data, t_pxl *pxl, int x, int y)
{
	int i;
	double	temp;

	pxl->curr[0] = 0;
	pxl->curr[1] = 0;
	calc_axis(x, y, pxl);
	data->c->r = ((pxl->curr[0] - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);
	data->c->i = ((WIN_HEIGHT / 2) - pxl->curr[1]) * (4.0) / WIN_HEIGHT;
	data->z->r = 0;
	data->z->i = 0;
	while(++i < data->loop_max)
	{
		temp = data->z->r;
		data->z->r = (data->z->r * data->z->r) - (data->z->i * data->z->i) \
		+ data->c->r;
		data->z->i = 2 * temp * data->z->i + data->c->i;
		if ((data->z->r * data->z->r) + (data->z->i * data->z->i) > 4)
			break;
	}
	return (i);
}

int	julia(t_data *data, t_pxl *pxl, int x, int y)
{
	return (0);
}