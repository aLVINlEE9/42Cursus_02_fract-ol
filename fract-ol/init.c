/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:31:19 by seungsle          #+#    #+#             */
/*   Updated: 2022/01/20 17:37:27 by seungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void	init_sturct(t_fractol *frac)
{
	frac->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	frac->img = (t_img *)malloc(sizeof(t_img));
	frac->z = (t_z *)malloc(sizeof(t_z));
	frac->c = (t_c *)malloc(sizeof(t_c));
	frac->axis = (t_axis *)malloc(sizeof(t_axis));
	frac->clr = (t_clr *)malloc(sizeof(t_clr));
	if (!frac->mlx || !frac->img || !frac->z || !frac->c || !frac->axis \
	|| !frac->clr)
		free_exit_2(frac);
	frac->loop_max = 100;
	frac->loop = 0;
	init_mlx_struct(frac->mlx);
	init_img_struct(frac->mlx, frac->img);
	init_zc_struct(frac->z, frac->c);
	init_ax_clr_struct(frac->axis, frac->clr);
	return ;
}

void	init_mlx_struct(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, \
	"fractol");
	return ;
}

void	init_img_struct(t_mlx *mlx, t_img *img)
{
	img->img_ptr = mlx_new_image(mlx->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT);
	img->data = (char *)mlx_get_data_addr(img->img_ptr, \
	&img->bpp, &img->size_l, &img->endian);
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

void	init_ax_clr_struct(t_axis *axis, t_clr *clr)
{
	axis->x = 0;
	axis->y = 0;
	clr->r = 0;
	clr->g = 0;
	clr->b = 0;
	return ;
}