/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:14:53 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 01:13:54 by seungsle         ###   ########.fr       */
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

void	put_color(t_data *data, t_img *img, int x, int y)
{
	int		offset;
	int		loop;

	loop = data->function(data, data->pxl, x, y);
	if (loop == data->loop_max)
	{
		data->rgb->r = 0;
		data->rgb->g = 0;
		data->rgb->b = 0;
	}
	else
	{
		data->rgb->r = (255 - loop * data->rgb->set_r);
		data->rgb->g = (255 - loop * data->rgb->set_g);
		data->rgb->b = (255 - loop * data->rgb->set_b);
	}
	offset = (x * (img->bpp / 8)) + (y * img->size_l);
	img->data[offset] = data->rgb->r;
	img->data[offset + 1] = data->rgb->g;
	img->data[offset + 2] = data->rgb->b;
	//printf("1\n");
	return ;
}

void	pxl_to_img(t_data *data)
{
	int		count_h;
	int		count_w;

	count_h = -1;
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
			put_color(data, data->img, count_w, count_h);
	}
	return ;
}