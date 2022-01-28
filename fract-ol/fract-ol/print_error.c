/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:09:53 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	error_param(int error, t_data *data)
{
	if (error == MANY_PARAM_ERROR)
		ft_putstr_fd("Error : too many parameters", 1);
	else if (error == INVALID_PARAM_ERROR)
		ft_putstr_fd("Error : invalid parameters", 1);
	free(data);
}

void	error_malloc(int error, t_data *data)
{
	if (error == MLX_MALLOC_ERROR)
		ft_putstr_fd("Error : mlx malloc failed", 1);
	else if (error == IMG_MALLOC_ERROR)
	{
		ft_putstr_fd("Error : img malloc failed", 1);
		free(data->mlx);
	}
	free(data);
}

void	error_detected(int error, t_data *data)
{
	if (error == DATA_MALLOC_ERROR)
		ft_putstr_fd("Error : data malloc failed", 1);
	else if (error == MANY_PARAM_ERROR || error == INVALID_PARAM_ERROR)
		error_param(error, data);
	else if (error == MLX_MALLOC_ERROR || error == IMG_MALLOC_ERROR)
		error_malloc(error, data);
	exit(1);
}