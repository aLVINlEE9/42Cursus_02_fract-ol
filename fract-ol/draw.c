/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:22:21 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 22:19:00 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	draw(t_fractol *frac)
{
	int count_h;
	int count_w;
	
	init_xy(frac);
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			init_xy(frac);
			frac->x = count_w;
			frac->y = count_h;
			frac->img.data[count_h * IMG_WIDTH + count_w] = frac->function(frac);
		}
	}
	return ;
}