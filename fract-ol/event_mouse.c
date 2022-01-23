/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:36:50 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 20:49:48 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	mouse_scroll(int button, int x, int y, void *param)
{
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	frac->zoom = 2;
	frac->loop_max = 42;
	frac->loop_max *= frac->zoom;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	frac->center[0] = ((x - WIN_WIDTH / 2) * (4.0 / frac->zoom) / WIN_WIDTH);
	frac->center[1] = ((WIN_HEIGHT / 2) - y) * (4.0 / frac->zoom) / WIN_HEIGHT;
	printf("(%f, %f)\n", frac->center[0], frac->center[1]);
	draw(frac);
	mlx_clear_window(frac->mlx->mlx_ptr, frac->mlx->win);
	mlx_put_image_to_window(frac->mlx->mlx_ptr, frac->mlx->win, \
	frac->img->img_ptr, 0, 0);
	return (0);
}