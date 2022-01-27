/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:19:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/27 22:11:02 by seungsle         ###   ########.fr       */
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
		exit(1);
	if (argc == 2)
		input_cmp(argv, frac);
	else
		free_exit_1(frac);
	return ;
}

void	loop(t_fractol *frac)
{
	mlx_clear_window(frac->mlx->mlx_ptr, frac->mlx->win);
	draw(frac);
	mlx_put_image_to_window(frac->mlx->mlx_ptr, frac->mlx->win, \
	frac->img->img_ptr, 0, 0);
	return ;
}

void	fractol(t_fractol *frac)
{
	init_sturct(frac);
	draw(frac);
	mlx_put_image_to_window(frac->mlx->mlx_ptr, frac->mlx->win, \
	frac->img->img_ptr, 0, 0);
	mlx_key_hook(frac->mlx->win, listener, (void *)frac);
	mlx_hook(frac->mlx->win, 6, (1L << 6), mouse_move, (void *)frac);
	mlx_hook(frac->mlx->win, 4, (1L << 2), mouse_scroll, (void *)frac);
	mlx_loop(frac->mlx->mlx_ptr);
	return ;
}

int	main(int argc, char **argv)
{
	t_fractol	*frac;

	frac = (t_fractol *)malloc(sizeof(t_fractol));
	check_valid(argc, argv, frac);
	fractol(frac);
	free_exit_2(frac);
	return (0);
}
