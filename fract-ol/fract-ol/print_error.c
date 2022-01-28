/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/29 00:57:11 by seungsle         ###   ########.fr       */
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

void	error_malloc_1(int error, t_data *data)
{
	if (error == MLX_MALLOC_ERROR)
		return (ft_putstr_fd("Error : mlx malloc failed", 1));
	free(data->mlx);
	if (error == IMG_MALLOC_ERROR)
		return (ft_putstr_fd("Error : img malloc failed", 1));
	free(data->img);
	if (data->rgb == NULL && error == RGB_MALLOC_ERROR)
		return (ft_putstr_fd("Error : rgb malloc failed", 1));
	free(data->rgb);
	if (error == PXL_MALLOC_ERROR)
		return (ft_putstr_fd("Error : rgb malloc failed", 1));
	return ;
}

void	error_malloc_2(int error, t_data *data)
{
	free(data->pxl);
	if (data->c == NULL && data->z == NULL && error == ZC_MALLOC_ERROR)
		return ;
	else if (data->c == NULL && error == ZC_MALLOC_ERROR)
		return (free(data->z));
	else if (data->z == NULL && error == ZC_MALLOC_ERROR)
		return (free(data->c));
	free(data->z);
	free(data->c);
	if (error == AXIS_MALLOC_ERROR)
		return ;
	return ;
}

void	error_detected(int error, t_data *data)
{
	if (error == DATA_MALLOC_ERROR)
		ft_putstr_fd("Error : data malloc failed", 1);
	else if (error == MANY_PARAM_ERROR || error == INVALID_PARAM_ERROR)
		error_param(error, data);
	else if (error < -3 && error > -8)
		error_malloc_1(error, data);
	else if (error < -7 && error > -10)
		error_malloc_2(error, data);
	free(data);
	exit(1);
}