/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:50:05 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/06 17:16:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_1(int keycode)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
}

void	key_2(int keycode, t_data *data)
{
	double		move;

	move = 10 / (data->pxl.last_zoom / 10);
	if (keycode == KEY_UP)
		data->pxl.last[1] += move;
	else if (keycode == KEY_DOWN)
		data->pxl.last[1] -= move;
	else if (keycode == KEY_RIGHT)
		data->pxl.last[0] += move;
	else if (keycode == KEY_LEFT)
		data->pxl.last[0] -= move;
	return ;
}

void	key_3(int keycode, t_data *data)
{
	if (keycode == KEY_ONE)
		data->rgb.set_r += 5;
	else if (keycode == KEY_TWO)
		data->rgb.set_g += 5;
	else if (keycode == KEY_THREE)
		data->rgb.set_b += 5;
	return ;
}

void	key_4(int keycode, t_data *data)
{
	if (keycode == KEY_P)
		data->pxl.last_zoom *= 1.1;
	else if (keycode == KEY_M)
		data->pxl.last_zoom *= 0.9;
	if (data->loop_mul < data->pxl.last_zoom / 300)
	{
		data->loop_mul++;
		data->loop_max = 42 * (data->loop_mul + 1);
	}
}

int	listener(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key_1(keycode);
	key_2(keycode, data);
	key_3(keycode, data);
	key_4(keycode, data);
	loop(data);
	return (0);
}
