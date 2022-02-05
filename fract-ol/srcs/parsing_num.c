/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:16:35 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 18:57:26 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_num(char *str)
{
	if (*str == '-')
	{
		while (*++str)
		{
			if ((*str >= '0' && *str <= '9') || *str == '.')
				continue ;
			else
				error_detected(INVALID_NUMBER);
		}
	}
	else if (*str >= '0' && *str <= '9')
	{
		while (*++str)
		{
			if ((*str >= '0' && *str <= '9') || *str == '.')
				continue ;
			else
				error_detected(INVALID_NUMBER);
		}
	}
	else
		error_detected(INVALID_NUMBER);
}

void	parsing_num(char *ar2, char *ar3, t_data *data)
{
	init_juliac(data);
	check_num(ar2);
	check_num(ar3);
	data->juliac.cr = ft_atod(ar2, data);
	data->juliac.ci = ft_atod(ar3, data);
}
