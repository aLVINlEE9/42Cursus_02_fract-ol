/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:50:18 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 19:03:13 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int mouse_scroll(int button, int x, int y, void *param)
{
	t_data	*data;
	t_pxl	*pxl;

	data = (t_data *)param;
	pxl = (t_pxl *)data->pxl;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	if (button == SCROLL_UP)
		pxl->curr_zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		pxl->curr_zoom *= 0.9;
	else
		return (0);
	calc_axis(x, y, pxl);
	loop(data);
	return (0);
}