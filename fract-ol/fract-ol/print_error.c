/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 19:02:33 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	error_param(int error, t_data *data)
{
	if (error == MANY_PARAM_ERROR)
		ft_putstr_fd("Error : too many parameters", 1);
	else if (error == INVALID_PARAM_ERROR)
		ft_putstr_fd("Error : invalid parameters", 1);
}

void	error_malloc(int error, t_data *data)
{
	if (error == MLX_MALLOC_ERROR)
		return (ft_putstr_fd("Error : mlx malloc failed", 1));
	free(data->mlx);
	if (error == IMG_MALLOC_ERROR)
		return (ft_putstr_fd("Error : img malloc failed", 1));
	free(data->img);
	if (error == RGB_MALLOC_ERROR)
		return (ft_putstr_fd("Error : rgb malloc failed", 1));
	free(data->rgb);
	if (error == PXL_MALLOC_ERROR)
		return (ft_putstr_fd("Error : rgb malloc failed", 1));
	return ;
}

void	error_detected(int error, t_data *data)
{
	if (error == DATA_MALLOC_ERROR)
		ft_putstr_fd("Error : data malloc failed", 1);
	else if (error == MANY_PARAM_ERROR || error == INVALID_PARAM_ERROR)
		error_param(error, data);
	else if (error < -3 && error > -8)
		error_malloc(error, data);
	free(data);
	exit(1);
}