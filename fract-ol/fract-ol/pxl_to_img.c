/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxl_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:14:53 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:39:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	pix_to_img(t_data *data)
{
	int		count_h;
	int		count_w;
	t_axis	*axis;

	axis = frac->axis;
	count_h = -1;
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			axis->x = count_w;
			axis->y = count_h;
			put_color(frac, frac->img, count_w, count_h);
		}
	}
	return ;
}