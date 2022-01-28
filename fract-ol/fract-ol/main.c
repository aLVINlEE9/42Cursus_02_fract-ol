/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:19:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/28 16:33:28 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	check_valid(argc, argv, data);
	execute(frac);
	free_exit_2(frac);
	return (0);
}
