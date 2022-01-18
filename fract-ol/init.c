/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:31:19 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/18 22:16:55 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_sturct(t_fractol *frac)
{
	frac->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	frac->z = (t_z *)malloc(sizeof(t_z));
	frac->c = (t_c *)malloc(sizeof(t_c));
	frac->axis = (t_axis *)malloc(sizeof(t_axis));
	if (!frac->mlx || !frac->z || !frac->c || !frac->axis)
		free_exit(frac);
	init_mlx_struct(frac->mlx);
	init_img_struct(frac->mlx, frac->img);
	init_zc_struct(frac->z, frac->c);
	init_axis_struct(frac->axis);
}

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	return ;
}

void	init_img_struct(t_mlx *mlx, t_img img)
{
	img.img_ptr = mlx_new_image(mlx->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, \
	&img.bpp, &img.size_l, &img.endian);
	return ;
}

void	init_zc_struct(t_z *z, t_c *c)
{
	z->i = 0;
	z->r = 0;
	c->i = 0;
	c->r = 0;
	return ;
}

void	init_axis_struct(t_axis *axis)
{
	axis->x = 0;
	axis->y = 0;
}