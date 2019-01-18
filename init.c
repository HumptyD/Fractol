/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:13:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/18 22:53:33 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_window_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, W_WIDTH, W_HEIGHT, var->f.set_name);
}

static void ft_img_init(t_var *var)
{
	var->img.image = mlx_new_image(var->mlx, W_WIDTH, W_HEIGHT);
	var->img.ptr = mlx_get_data_addr(var->img.image,
			&var->img.bpp, &var->img.size_line, &var->img.endian);
	var->img.bpp /= 8;
}

static void	ft_data_init(t_var *var)
{
	var->data.z = ft_memalloc(sizeof(double) * W_WIDTH * W_HEIGHT * 2);
	var->data.c = ft_memalloc(sizeof(double) * W_WIDTH * W_HEIGHT * 2);
	var->data.i = ft_memalloc(sizeof(int) * W_WIDTH * W_HEIGHT);
}

static void	ft_fractal_init(t_var *var)
{
	var->ms.pressed = 0;
	var->scale = 1;
	var->iter = 100;
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

void	init(t_var *var)
{
	ft_window_init(var);
	ft_img_init(var);
	ft_ocl_init(var);
	ft_data_init(var);
	ft_fractal_init(var);
}

void	ft_fractal_name_init(t_var *var, char *name)
{
	var->f.set_name = name;
	if (!ft_strcmp(name, "mandelbrot"))
		var->f.name = 1;
	else if (!ft_strcmp(name, "julia"))
		var->f.name = 2;
	else if (!ft_strcmp(name, "burningship"))
		var->f.name = 3;
	else
		display_error(1, "usage: ./fractol \"mandelbrot\", \"julia\", \"burningship\"");
}
