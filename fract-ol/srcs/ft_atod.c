/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:21:03 by seungsle          #+#    #+#             */
/*   Updated: 2022/02/05 18:28:52 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	get_decimal(char *str, double db_ret, long long p, t_data *data)
{
	int		cnt;

	cnt = 0;
	while (*str >= '0' && *str <= '9')
	{
		db_ret *= 10;
		db_ret += (p * (*str - '0'));
		str++;
		cnt++;
	}
	db_ret /= pow(10, cnt);
	data->juliac.decimal = db_ret;
}

void	get_num(char *str, long long ret, long long p, t_data *data)
{
	double	db_ret;

	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += (p * (*str - '0'));
		str++;
	}
	data->juliac.integer = ret;
	if (*str == '.')
	{
		db_ret = 0;
		str++;
		get_decimal(str, db_ret, p, data);
	}
}

double	ft_atod(char *str, t_data *data)
{
	long long	ret;
	long long	p;
	double		db_ret;

	ret = 0;
	p = 1;
	while (*str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			p *= -1;
		str++;
	}
	get_num(str, ret, p, data);
	printf("%lld %f\n", data->juliac.integer, data->juliac.decimal);
	db_ret = data->juliac.integer + data->juliac.decimal;
	data->juliac.integer = 0;
	data->juliac.decimal = 0;
	printf("%f\n", db_ret);
	return (db_ret);
}
