/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:03:30 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

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
	init_mlx(data);
	init_img(data);
	return ;
}
