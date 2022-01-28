/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:33:34 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:49:39 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	loop(t_data *data)
{
	t_mlx	*mlx;
	t_img	*img;

	mlx = (t_mlx *)data->mlx;
	img = (t_img *)data->img;
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	plx_to_img(data);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
}

void	execute(t_data *data)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)data->mlx;
	init(data);
	loop(data);
	mlx_key_hook(mlx->win, listener, (void *)data);
	mlx_hook(mlx->win, 4, (1L << 2), mouse_scroll, (void *)data);
	mlx_loop(mlx->mlx_ptr);
}