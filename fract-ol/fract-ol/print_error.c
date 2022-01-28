/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:14:00 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 16:26:56 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void error_detected(int error, t_data *data)
{
	if (error == MALLOC_ERROR)
		ft_putstr_fd("Error : malloc failed", 1);
	else if (error == MANY_PARAM_ERROR)
		ft_putstr_fd("Error : too many parameters", 1);
	else if (error == INVALID_PARAM_ERROR)
		ft_putstr_fd("Error : invalid parameters", 1);
	if (error != MALLOC_ERROR)
		free(data);
	exit(1);
}