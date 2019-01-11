/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:13:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 20:51:41 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_var(t_var *var, char *name)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, W_WIDTH, W_HEIGHT, name);
	var->fractal = name;
	var->cx.re = 0.;
	var->cx.im = 0.;
	var->mnd.xs = -5;
	var->mnd.ys = -2.2;
	var->opt.scale = 300;
	var->opt.iter = 100;
}

void	init_image(t_var *var)
{
	var->img = ft_memalloc(sizeof(t_img));
	display_error(!var->img, "error: memmory is not allocated");
	var->img->image = mlx_new_image(var->mlx, W_WIDTH, W_HEIGHT);
	var->img->ptr = mlx_get_data_addr(var->img->image,
			&var->img->bpp, &var->img->size_line, &var->img->endian);
	var->img->bpp /= 8;
}
