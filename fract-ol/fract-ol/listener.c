/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:50:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 00:14:48 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	key_1(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
		mlx_destroy_image(data->mlx->mlx_ptr, data->img->img_ptr);
		exit(0);
	}
}

int	listener(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key_1(keycode, data);
	printf("%d ", keycode);
	return (0);
}