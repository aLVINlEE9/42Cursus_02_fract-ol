/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:36:50 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 18:01:31 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

void zoom(int x, int y, t_fractol *frac)
{
	if (frac->last[2] != frac->zoom)
	{
		calc_axis(x, y, frac);
		frac->last[0] = frac->curr[0];
		frac->last[1] = frac->curr[1];
		if (frac->loop_mul < frac->zoom / 1000)
		{
			frac->loop_mul += 1;
			frac->loop_max = 42 * (frac->loop_mul + 1);
		}
		loop(frac);
	}
	else
	{
		frac->last[0] = x;
		frac->last[1] = y;
	}
}

int mouse_scroll(int button, int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	//frac->last[2] = frac->zoom;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	if (button == SCROLL_UP)
	{
		frac->zoom *= 1.1;
	}
	else if (button == SCROLL_DOWN)
	{
		frac->zoom *= 0.9;
	}
	printf("%d | (%d %d) [%f, %f] x%f x%f %f||\n", button, x, y, frac->curr[0], frac->curr[1], frac->last[2], frac->zoom, frac->loop_max);
	zoom(x, y, frac);
	frac->last[2] = frac->zoom;
	return (0);
}

void calc_axis(int x, int y, t_fractol *frac)
{
	if (frac->zoom == 1.0)
	{
		frac->curr[0] = x;
		frac->curr[1] = y;
	}
	else
	{
		if (x < 400)
			frac->curr[0] = frac->last[0] - ((WIN_WIDTH / 2 - x) / frac->last[2]);
		else if (x == 400)
			frac->curr[0] = frac->last[0];
		else
			frac->curr[0] = frac->last[0] + ((x - WIN_WIDTH / 2) / frac->last[2]);
		if (y < 400)
			frac->curr[1] = frac->last[1] - ((WIN_HEIGHT/ 2 - y) / frac->last[2]);
		else if (y == 400)
			frac->curr[1] = frac->last[1];
		else
			frac->curr[1] = frac->last[1] + ((y - WIN_HEIGHT / 2) / frac->last[2]);
	}

	//printf("[%d %f] [%d %f]\n", x, frac->curr[0], y, frac->curr[1]);
}