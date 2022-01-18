/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:19:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 22:15:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	input_cmp(char **argv, t_fractol *frac)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		frac->function = mandelbrot;
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		frac->function = julia;
	else
		free_exit_1(frac);
	return ;
}

void	check_valid(int argc, char **argv, t_fractol *frac)
{
	if (frac == NULL)
		eixt(1);
	if (argc == 2)
		input_cmp(argv, frac);
	else
		free_exit_1(frac);
	return ;
}

void	fractol(t_fractol *frac)
{
	init_sturct(frac);
	draw(frac);
	mlx_put_image_to_window(frac->mlx->mlx_ptr, frac->mlx->win, \
	frac->img.img_ptr, 0, 0);
	mlx_loop(frac->mlx->mlx_ptr);
	return ;
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = (t_fractol *)malloc(sizeof(t_fractol));
	check_valid(argc, argv, frac);
	fractol(frac);
	return (0);
}
