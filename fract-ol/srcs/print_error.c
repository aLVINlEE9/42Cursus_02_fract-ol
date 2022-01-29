/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/30 01:50:10 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_param(int error, t_data *data)
{
	if (error == MANY_PARAM_ERROR)
		ft_putstr_fd("Error : too many parameters", 1);
	else if (error == INVALID_PARAM_ERROR)
		ft_putstr_fd("Error : invalid parameters", 1);
}

void	error_detected(int error, t_data *data)
{
	if (error == MLX_INIT_ERROR)
		ft_putstr_fd("Error : mlx_init() failed", 1);
	else if (error == MLX_NEW_WINDOW_ERROR)
		ft_putstr_fd("Error : mlx_new_window() failed", 1);
	else if (error == MLX_NEW_IMAGE_ERROR)
		ft_putstr_fd("Error : mlx_new_image() failed", 1);
	else if (error == MLX_GET_DATA_ADDR_ERROR)
		ft_putstr_fd("Error : mlx_get_data_addr() failed", 1);
	else if (error == MANY_PARAM_ERROR || error == INVALID_PARAM_ERROR)
		error_param(error, data);
	exit(1);
}
