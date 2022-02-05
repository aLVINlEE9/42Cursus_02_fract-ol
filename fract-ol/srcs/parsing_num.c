/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:16:35 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 18:19:04 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	parsing_num(char *ar2, char *ar3, t_data *data)
{
	data->juliac.cr = ft_atod(ar2, data);
	data->juliac.ci = ft_atod(ar3, data);
}
