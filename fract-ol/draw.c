/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:22:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/20 13:37:12 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	put_color(t_fractol *frac, t_img *img, int x, int y)
{
	frac->loop = frac->function(frac, frac->axis, frac->z, frac->c);
	img->data[x * WIN_WIDTH + y];
	return ;
}

void	draw(t_fractol *frac)
{
	int count_h;
	int count_w;
	t_axis *axis;
	
	axis = frac->axis;
	count_h = -1;
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			axis->x = count_w;
			axis->y = count_h;
			put_color(frac, frac->img, count_w, count_h);
		}
	}
	return ;
}