/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:06 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/19 00:25:43 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	free_exit_1(t_fractol *frac)
{
	free(frac);
	exit(1);
	return ;
}

void	free_exit_2(t_fractol *frac)
{
	free(frac->mlx);
	free(frac->img);
	free(frac->z);
	free(frac->c);
	free(frac->axis);
	free(frac);
	exit(1);
	return ;
}
