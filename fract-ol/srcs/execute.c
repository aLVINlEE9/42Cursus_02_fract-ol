/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:33:34 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/30 01:49:33 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	loop(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT);
	if (data->img.img_ptr)
	{
		pxl_to_img(data);
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win, \
		data->img.img_ptr, 0, 0);
		put_str(data);
		mlx_destroy_image(data->mlx.mlx_ptr, data->img.img_ptr);
	}
	else
		error_detected(MLX_NEW_IMAGE_ERROR, data);
}

void	execute(t_data *data)
{
	init(data);
	data->mlx.mlx_ptr = mlx_init();
	if (data->mlx.mlx_ptr)
	{
		data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, \
		WIN_HEIGHT, "fractol");
		if (data->mlx.win)
		{
			loop(data);
			mlx_key_hook(data->mlx.win, listener, (void *)data);
			mlx_hook(data->mlx.win, 4, (1L << 2), mouse_scroll, (void *)data);
			mlx_loop(data->mlx.mlx_ptr);
		}
		else
			error_detected(MLX_NEW_WINDOW_ERROR, data);
	}
	else
		error_detected(MLX_INIT_ERROR, data);
}
