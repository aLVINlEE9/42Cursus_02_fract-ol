/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:08 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/27 23:10:23 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	key_1(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_ONE)
		frac->clr->r_set += 5;
	else if (keycode == KEY_TWO)
		frac->clr->g_set += 5;
	else if (keycode == KEY_THREE)
		frac->clr->b_set += 5;
	printf("%d | ", keycode);
	return (0);
}

int key_2(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if (keycode == KEY_UP)
		frac->last[1] -= 10;
	else if (keycode == KEY_DOWN)
		frac->last[1] += 10;
	else if (keycode == KEY_RIGHT)
		frac->last[0] += 10;
	else if (keycode == KEY_LEFT)
		frac->last[0] -= 10;
	return (0);
}

int key_3(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if (keycode == KEY_P)
	{
		frac->zoom *= 1.1;
		zoom(WIN_WIDTH/ 2, WIN_HEIGHT/ 2, frac);
	}
	else if (keycode == KEY_M)
	{
		frac->zoom *= 0.9;
		zoom(WIN_WIDTH/ 2, WIN_HEIGHT/ 2, frac);
	}
	return (0);
}

int	listener(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	key_1(keycode, param);
	key_2(keycode, param);
	key_3(keycode, param);
	loop(frac);
	return (0);
}