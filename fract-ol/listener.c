/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:08 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/23 23:19:48 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"
#include <stdio.h>

int	listener(int keycode, void *param)
{
	t_fractol *frac;

	frac = (t_fractol *)param;
	mouse_scroll(keycode, param);
	loop(frac);
	return (0);
}