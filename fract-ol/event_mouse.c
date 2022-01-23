/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:36:50 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 23:43:47 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	mouse_scroll(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if (keycode == SCROLL_UP)
	{
		frac->zoom *= 1.1;
	}
	else if (keycode == SCROLL_DOWN)
	{
		frac->zoom *= 0.9;
	}
	frac->loop_max *= frac->zoom;
	printf("%d | ", keycode);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	//frac->zoom = 2;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	frac->center[0] = ((x - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);
	frac->center[1] = ((WIN_HEIGHT / 2) - y) * (4.0) / WIN_HEIGHT;
	printf("(%f, %f) x%f\n", frac->center[0], frac->center[1], frac->zoom);
	loop(frac);
	return (0);
}