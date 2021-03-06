/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:57:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 17:16:19 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_zc(t_data *data)
{
	data->z.r = 0;
	data->z.i = 0;
	data->c.r = 0;
	data->c.i = 0;
	return ;
}

void	init_axis(t_data *data)
{
	data->axis.x = 0;
	data->axis.y = 0;
}

void	init_juliac(t_data *data)
{
	data->juliac.ci = 0;
	data->juliac.cr = 0;
	data->juliac.decimal = 0;
	data->juliac.integer = 0;
}
