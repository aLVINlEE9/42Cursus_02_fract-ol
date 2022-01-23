/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:22:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 19:22:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	put_color(t_fractol *frac, t_img *img, int x, int y)
{
	t_clr	*clr;
	int		offset;
	int		loop;

	clr = frac->clr;
	loop = frac->function(frac, frac->axis, frac->z, frac->c);
	if (loop == frac->loop_max * frac->zoom)
	{
		clr->r = 0;
		clr->g = 0;
		clr->b = 0;
	}
	else
	{
		clr->r = (loop * 7) % 255;
		clr->g = (142 + (loop * 2)) % 255;
		clr->b = (255 - (loop * 8)) % 255;
	}
	offset = (x * (img->bpp / 8)) + (y * img->size_l);
	img->data[offset] = clr->r;
	img->data[offset + 1] = clr->g;
	img->data[offset + 2] = clr->b;
	return ;
}

void	draw(t_fractol *frac)
{
	int		count_h;
	int		count_w;
	t_axis	*axis;

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
