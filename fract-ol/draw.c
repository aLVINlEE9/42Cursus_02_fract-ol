/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:22:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/19 00:27:15 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	get_color(t_fractol *frac)
{
	int iter;

	iter = frac->function(frac);
	if (iter < frac->loop_max)
		return (0x00FFFFFF);
	else
		return (0x00000000);
}

void	draw(t_fractol *frac)
{
	int count_h;
	int count_w;
	t_axis *axis;
	
	axis = frac->axis;
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			axis->x = count_w;
			axis->y = count_h;
			frac->img->data[count_h * IMG_WIDTH + count_w] = get_color(frac);
		}
	}
	return ;
}