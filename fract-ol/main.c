/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:19:20 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 20:11:32 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void free_exit(t_fractol *frac)
{
	free(frac->mlx);
	free(frac);
	exit(1);
}

int check_valid(int argc, char **argv, t_fractol *frac)
{
	if (frac == NULL)
		return (FALSE);
	if (argc == 2)
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			frac->function = mandelbrot;
			return (TRUE);
		}
		else if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			frac->function = julia;
			return (TRUE);
		}
		else
			free(frac);
	}
	return (FALSE);
}

void draw(t_fractol *frac)
{
	int count_h;
	int count_w;
	
	count_h = -1;
	while (++count_h < IMG_HEIGHT)
	{
		count_w = -1;
		while (++count_w < IMG_WIDTH)
		{
			if (count_h <= 100)
				frac->img.data[count_h * IMG_WIDTH + count_w] = 0xFFFFFF;
			else
				frac->img.data[count_h * IMG_WIDTH + count_w] = 0xFF0000;
		}
	}
}

void fractol(t_fractol *frac)
{
	frac->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if(frac->mlx == NULL)
		free_exit(frac);
	frac->mlx->mlx_ptr = mlx_init();
	frac->mlx->win = mlx_new_window(frac->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	frac->img.img_ptr = mlx_new_image(frac->mlx->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
	frac->img.data = (int *)mlx_get_data_addr(frac->img.img_ptr, \
	&frac->img.bpp, &frac->img.size_l, &frac->img.endian);
	draw(frac);
	mlx_put_image_to_window(frac->mlx->mlx_ptr, frac->mlx->win, \
	frac->img.img_ptr, 0, 0);
	mlx_loop(frac->mlx->mlx_ptr);

	return ;
}

int main(int argc, char **argv)
{
	t_fractol *frac;

	frac = (t_fractol *)malloc(sizeof(t_fractol));
	if (!check_valid(argc, argv, frac))
		return (0);
	fractol(frac);
	return (0);
}