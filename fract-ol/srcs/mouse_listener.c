/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:50:18 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/30 01:50:07 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_zoomed_center(int x, int y, t_pxl *pxl, t_data *data)
{
	calc_axis(x, y, pxl);
	pxl->last[0] = pxl->curr[0];
	pxl->last[1] = pxl->curr[1];
	pxl->last_zoom = pxl->curr_zoom;
	if (data->loop_mul < pxl->curr_zoom / 300)
	{
		data->loop_mul++;
		data->loop_max = 42 * (data->loop_mul + 1);
	}
	return ;
}

int	mouse_scroll(int button, int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return (0);
	if (button == SCROLL_UP)
		data->pxl.curr_zoom *= 1.1;
	else if (button == SCROLL_DOWN)
		data->pxl.curr_zoom *= 0.9;
	else
		return (0);
	get_zoomed_center(x, y, &(data->pxl), data);
	loop(data);
	return (0);
}
