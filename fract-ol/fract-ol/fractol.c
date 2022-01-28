/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:28:52 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 02:18:40 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	put_str(t_data *data)
{
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win, 0, 50, 16777215,
			"zoom : x");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win, 60, 50, 16777215,
			ft_itoa((int)data->pxl->last_zoom));
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win, 0, 100, 16777215,
			"iteration : ");
	mlx_string_put(data->mlx->mlx_ptr, data->mlx->win, 80, 100, 16777215,
			ft_itoa((int)data->loop_max));
}

int	mandelbrot(t_data *data, t_pxl *pxl, int x, int y)
{
	int i;
	double	temp;

	i = -1;
	pxl->curr[0] = 0;
	pxl->curr[1] = 0;
	calc_axis(x, y, pxl);
	//printf("%d %d\n", x, y);
	data->c->r = ((pxl->curr[0] - WIN_WIDTH / 2) * (4.0) / WIN_WIDTH);
	data->c->i = ((WIN_HEIGHT / 2) - pxl->curr[1]) * (4.0) / WIN_HEIGHT;
	data->z->r = 0;
	data->z->i = 0;
	while(++i < data->loop_max)
	{
		temp = data->z->r;
		data->z->r = (data->z->r * data->z->r) - (data->z->i * data->z->i) \
		+ data->c->r;
		data->z->i = 2 * temp * data->z->i + data->c->i;
		if ((data->z->r * data->z->r) + (data->z->i * data->z->i) > 4)
			break;
	}
	return (i);
}

int	julia(t_data *data, t_pxl *pxl, int x, int y)
{
	return (0);
}