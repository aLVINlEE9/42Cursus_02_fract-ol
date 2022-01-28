/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:33:34 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:12:00 by seungsle         ###   ########.fr       */
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
	draw(frac);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
}

void	execute(t_data *data)
{
	init(data);
	loop(data);
}