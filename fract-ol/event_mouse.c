/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:36:50 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/27 18:12:06 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>


int mouse_scroll(int button, int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	if (button == SCROLL_UP)
	{
		frac->zoom *= 1.1;
	}
	else if (button == SCROLL_DOWN)
	{
		frac->zoom *= 0.9;
	}
	frac->loop_max *= frac->zoom;
	frac->center[0] = ((frac->curr[0] - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);
	frac->center[1] = ((WIN_HEIGHT / 2) - frac->curr[1]) * (4.0) / WIN_HEIGHT;
	printf("%d | [%f, %f] x%f ||", button, frac->center[0], frac->center[1], frac->zoom);
	frac->last[0] = x;
	frac->last[1] = y;
	frac->last[2] = frac->zoom;
	loop(frac);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	//frac->zoom = 2;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	if (frac->zoom == 1.0)
	{
		frac->curr[0] = x;
		frac->curr[1] = y;
	}
	else
	{
		if (x < 400 || y < 400)
		{
			frac->curr[0] = frac->last[0] - (x / frac->last[2]);
			frac->curr[1] = frac->last[1] - (y / frac->last[2]);
		}
		else if(x > 400 || y > 400)
		{
			frac->curr[0] = frac->last[0] + (x / frac->last[2]);
			frac->curr[1] = frac->last[1] + (y / frac->last[2]);
		}
		else
		{
			frac->curr[0] = frac->last[0];
			frac->curr[1] = frac->last[1];
		}
	}
	printf("(%f, %f)\n", frac->curr[0], frac->curr[1]);
	//loop(frac);
	return (0);
}