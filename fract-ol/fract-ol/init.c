/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 18:49:02 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_pxl(t_data *data)
{
	t_pxl	*pxl;

	pxl = (t_pxl *)data->pxl;
	if (pxl == NULL)
		error_detected(PXL_MALLOC_ERROR, data);
	pxl->curr_zoom = 1;
	pxl->last_zoom = 1;
	pxl->curr[0] = 400;
	pxl->curr[1] = 400;
	pxl->last[0] = 400;
	pxl->last[1] = 400;
	return ;
}

void	init_rgb(t_data *data)
{
	t_rgb	*rgb;

	rgb = (t_rgb *)data->rgb;
	if (rgb == NULL)
		error_detected(RGB_MALLOC_ERROR, data);
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	rgb->set_r = 1;
	rgb->set_g = 1;
	rgb->set_b = 1;
	return ;
}

void	init_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)data->mlx;
	if (mlx == NULL)
		error_detected(MLX_MALLOC_ERROR, data);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	return ;
}

void	init_img(t_data *data)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = (t_mlx *)data->mlx;
	img = (t_img *)data->img;
	if (img == NULL)
		error_detected(IMG_MALLOC_ERROR, data);
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img->data = (char *)mlx_get_data_addr(img->img_ptr, \
	&img->bpp, &img->size_l, &img->endian);
	return ;
}

void	init(t_data *data)
{
	data->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	data->img = (t_img *)malloc(sizeof(t_img));
	data->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	data->pxl = (t_pxl *)malloc(sizeof(t_pxl));
	init_mlx(data);
	init_img(data);
	init_rgb(data);
	init_plx(data);
	return ;
}
