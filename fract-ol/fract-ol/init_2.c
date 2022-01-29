/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:57:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 17:24:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_zc(t_data *data)
{
	if (data->z == NULL || data->c == NULL)
		error_detected(ZC_MALLOC_ERROR, data);
	data->z->r = 0;
	data->z->i = 0;
	data->c->r = 0;
	data->c->i = 0;
	return ;
}

void	init_axis(t_data *data)
{
	if (data->axis == NULL)
		error_detected(AXIS_MALLOC_ERROR, data);
	data->axis->x = 0;
	data->axis->y = 0;
	return ;
}
