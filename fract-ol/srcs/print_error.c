/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 18:41:21 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_param(int error)
{
	if (error == INVALID_PARAM_NUM_ERROR)
		ft_putstr_fd("Error : not correct amount of parameters", 1);
	else if (error == INVALID_PARAM_ERROR)
		ft_putstr_fd("Error : invalid parameters", 1);
	else if (error == NONE_PARAM_ERROR)
		ft_putstr_fd("Error : there is no parameter", 1);
	else if (error == INVALID_NUMBER)
		ft_putstr_fd("Error : input value is not correct(integer or decimal)\
		", 1);
}

void	error_detected(int error)
{
	if (error == MLX_INIT_ERROR)
		ft_putstr_fd("Error : mlx_init() failed", 1);
	else if (error == MLX_NEW_WINDOW_ERROR)
		ft_putstr_fd("Error : mlx_new_window() failed", 1);
	else if (error == MLX_NEW_IMAGE_ERROR)
		ft_putstr_fd("Error : mlx_new_image() failed", 1);
	else if (error == MLX_GET_DATA_ADDR_ERROR)
		ft_putstr_fd("Error : mlx_get_data_addr() failed", 1);
	else if (error == INVALID_PARAM_NUM_ERROR || error == INVALID_PARAM_ERROR \
			|| error == NONE_PARAM_ERROR || error == INVALID_NUMBER)
		error_param(error);
	exit(1);
}
