/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:11:33 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/03 08:25:24 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_valid(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		error_detected(MANY_PARAM_ERROR);
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			data->function = mandelbrot;
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
			data->function = julia;
		else if (ft_strncmp(argv[1], "burningship", 11) == 0)
			data->function = burningship;
		else
			error_detected(INVALID_PARAM_ERROR);
	}
}
