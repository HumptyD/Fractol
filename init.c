/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:13:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/12 21:23:19 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, W_WIDTH, W_HEIGHT, "fractol");
	var->img = ft_memalloc(sizeof(t_img));
	display_error(!var->img, "error: memmory is not allocated");
	var->img->image = mlx_new_image(var->mlx, W_WIDTH, W_HEIGHT);
	var->img->ptr = mlx_get_data_addr(var->img->image,
			&var->img->bpp, &var->img->size_line, &var->img->endian);
	var->ms.pressed = 0;
	var->img->bpp /= 8;
	var->opt.scale = 1;
	var->opt.iter = 100;
}

void	fractal_data(t_var *var, int n)
{
	var->f.name = n;
	var->f.x_min = -2;
	var->f.y_min = -2;
	var->f.x_max = 2;
	var->f.y_max = 2;
	var->f.offx = 0;
	var->f.offy = 0;
	if (var->f.name == 2)
	{
		var->cx.re = 0.;
		var->cx.im = 0.;
	}
}

void	init_fractal(t_var *var, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		fractal_data(var, 1);
	else if (!ft_strcmp(name, "julia"))
		fractal_data(var, 2);
	else if (!ft_strcmp(name, "burningship"))
		fractal_data(var, 3);
	else
		display_error(1, "usage: ./fractol \"mandelbrot\", \"julia\", \"burningship\"");
}
