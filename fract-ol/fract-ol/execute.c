/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:33:34 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 02:14:14 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	loop(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	pxl_to_img(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, \
	data->img->img_ptr, 0, 0);
	put_str(data);
}

void	execute(t_data *data)
{
	init(data);
	loop(data);
	mlx_key_hook(data->mlx->win, listener, (void *)data);
	mlx_hook(data->mlx->win, 4, (1L << 2), mouse_scroll, (void *)data);
	//printf("[%f %f]\n", data->pxl->curr[0], data->pxl->curr[1]);
	mlx_loop(data->mlx->mlx_ptr);
}