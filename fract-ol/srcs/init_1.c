/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:47:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 18:33:41 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_pxl(t_data *data)
{
	data->pxl.curr_zoom = 1;
	data->pxl.last_zoom = 1;
	data->pxl.curr[0] = 400;
	data->pxl.curr[1] = 400;
	data->pxl.last[0] = 400;
	data->pxl.last[1] = 400;
}

void	init_rgb(t_data *data)
{
	data->rgb.r = 0;
	data->rgb.g = 0;
	data->rgb.b = 0;
	data->rgb.set_r = 1;
	data->rgb.set_g = 1;
	data->rgb.set_b = 1;
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = NULL;
	data->mlx.win = NULL;
}

void	init_img(t_data *data)
{
	data->img.img_ptr = NULL;
	data->img.data = NULL;
}

void	init(t_data *data)
{
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
