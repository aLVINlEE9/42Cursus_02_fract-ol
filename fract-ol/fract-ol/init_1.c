/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 00:47:34 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_pxl(t_data *data)
{
	if (data->pxl == NULL)
		error_detected(PXL_MALLOC_ERROR, data);
	data->pxl->curr_zoom = 1;
	data->pxl->last_zoom = 1;
	data->pxl->curr[0] = 400;
	data->pxl->curr[1] = 400;
	data->pxl->last[0] = 400;
	data->pxl->last[1] = 400;
	return ;
}

void	init_rgb(t_data *data)
{
	if (data->rgb == NULL)
		error_detected(RGB_MALLOC_ERROR, data);
	data->rgb->r = 0;
	data->rgb->g = 0;
	data->rgb->b = 0;
	data->rgb->set_r = 1;
	data->rgb->set_g = 1;
	data->rgb->set_b = 1;
	return ;
}

void	init_mlx(t_data *data)
{
	if (data->mlx == NULL)
		error_detected(MLX_MALLOC_ERROR, data);
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	return ;
}

void	init_img(t_data *data)
{
	if (data->img == NULL)
		error_detected(IMG_MALLOC_ERROR, data);
	data->img->img_ptr = mlx_new_image(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img->data = (char *)mlx_get_data_addr(data->img->img_ptr, \
	&data->img->bpp, &data->img->size_l, &data->img->endian);
	return ;
}

void	init(t_data *data)
{
	data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	data->img = (t_img *)malloc(sizeof(t_img));
	data->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	data->pxl = (t_pxl *)malloc(sizeof(t_pxl));
	data->z = (t_z *)malloc(sizeof(t_z));
	data->c = (t_c *)malloc(sizeof(t_c));
	data->axis = (t_axis *)malloc(sizeof(t_axis));
	data->loop_max = 42;
	data->loop_mul = 0;
	init_mlx(data);
	init_img(data);
	init_rgb(data);
	init_pxl(data);
	init_zc(data);
	init_axis(data);
	return ;
}
