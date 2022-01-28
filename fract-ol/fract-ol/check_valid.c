/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:11:33 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 17:11:21 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	check_valid(int argc, char **argv, t_data *data)
{
	if (data == NULL)
		error_detected(DATA_MALLOC_ERROR, data);
	if (argc != 2)
		error_detected(MANY_PARAM_ERROR, data);
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
			data->function = mandelbrot;
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
			data->function = julia;
		else
			error_detected(INVALID_PARAM_ERROR, data);
	}
}