/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:14:53 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/30 01:50:12 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calc_axis(int x, int y, t_pxl *pxl)
{
	if (x < 400)
		pxl->curr[0] = pxl->last[0] - ((WIN_WIDTH / 2 - x) / pxl->last_zoom);
	else if (x == 400)
		pxl->curr[0] = pxl->last[0];
	else
		pxl->curr[0] = pxl->last[0] + ((x - WIN_WIDTH / 2) / pxl->last_zoom);
	if (y < 400)
		pxl->curr[1] = pxl->last[1] + ((WIN_HEIGHT / 2 - y) / pxl->last_zoom);
	else if (y == 400)
		pxl->curr[1] = pxl->last[1];
	else
		pxl->curr[1] = pxl->last[1] - ((y - WIN_HEIGHT / 2) / pxl->last_zoom);
}

void	put_color(t_data *data, t_img *img, int x, int y)
{
	t_rgb	*rgb;
	int		offset;
	int		loop;

	rgb = (t_rgb *)&(data->rgb);
	loop = data->function(data, &(data->pxl), x, y);
	if (loop == data->loop_max)
	{
		rgb->r = 0;
		rgb->g = 0;
		rgb->b = 0;
	}
	else
	{
		rgb->r = (255 - loop * rgb->set_r);
		rgb->g = (255 - loop * rgb->set_g);
		rgb->b = (255 - loop * rgb->set_b);
	}
	offset = (x * (img->bpp / 8)) + (y * img->size_l);
	img->data[offset] = rgb->r;
	img->data[offset + 1] = rgb->g;
	img->data[offset + 2] = rgb->b;
	return ;
}

void	pxl_to_img(t_data *data)
{
	int		count_h;
	int		count_w;

	count_h = -1;
	data->img.data = (char *)mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bpp, &data->img.size_l, &data->img.endian);
	if (data->img.data)
	{
		while (++count_h < WIN_HEIGHT)
		{
			count_w = -1;
			while (++count_w < WIN_WIDTH)
				put_color(data, &(data->img), count_w, count_h);
		}
	}
	else
		error_detected(MLX_GET_DATA_ADDR_ERROR, data);
	return ;
}
