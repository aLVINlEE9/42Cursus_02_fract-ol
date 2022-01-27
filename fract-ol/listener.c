/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:08 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/27 15:22:26 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	key(int keycode, void *param)
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

int	listener(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	key(keycode, param);
	loop(frac);
	return (0);
}