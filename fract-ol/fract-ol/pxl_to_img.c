/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:14:53 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 18:38:42 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void calc_axis(int x, int y, t_pxl *pxl)
{
	if (x < 400)
		pxl->curr[0] = pxl->last[0] - ((WIN_WIDTH / 2 - x) / pxl->last_zoom);
	else if (x == 400)
		pxl->curr[0] = pxl->last[0];
	else
		pxl->curr[0] = pxl->last[0] + ((x - WIN_WIDTH / 2) / pxl->last_zoom);
	if (y < 400)
		pxl->curr[1] = pxl->last[1] - ((WIN_HEIGHT/ 2 - y) / pxl->last_zoom);
	else if (y == 400)
		pxl->curr[1] = pxl->last[1];
	else
		pxl->curr[1] = pxl->last[1] + ((y - WIN_HEIGHT / 2) / pxl->last_zoom);
}

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
		clr->r = (255 - loop * clr->r_set);
		clr->g = (255 - loop * clr->g_set);
		clr->b = (255 - loop * clr->b_set);
	}
	offset = (x * (img->bpp / 8)) + (y * img->size_l);
	img->data[offset] = clr->r;
	img->data[offset + 1] = clr->g;
	img->data[offset + 2] = clr->b;
	return ;
}

void	pix_to_img(t_data *data)
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