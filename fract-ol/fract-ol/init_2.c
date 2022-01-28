/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:57:09 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 19:57:34 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_zc(t_data *data)
{
	t_z		*z;
	t_c		*c;

	z = (t_z *)data->z;
	c = (t_c *)data->c;
	if (z == NULL || c == NULL)
		error_detected(ZC_MALLOC_ERROR, data);
	z->r = 0;
	z->i = 0;
	c->r = 0;
	c->i = 0;
	return ;
}