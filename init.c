/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:13:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/19 18:48:20 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_window_init(t_var *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, W_WIDTH, W_HEIGHT, var->f.set_name);
}

static void	ft_img_init(t_var *var)
{
	var->img.image = mlx_new_image(var->mlx, W_WIDTH, W_HEIGHT);
	var->img.ptr = mlx_get_data_addr(var->img.image,
			&var->img.bpp, &var->img.size_line, &var->img.endian);
	var->img.bpp /= 8;
}

static void	ft_data_init(t_var *var)
{
	var->data.z = ft_memalloc(sizeof(double) * W_WIDTH * W_HEIGHT * 2);
	display_error(!var->data.z, "error: memmory is not allocated");
	var->data.c = ft_memalloc(sizeof(double) * W_WIDTH * W_HEIGHT * 2);
	display_error(!var->data.c, "error: memmory is not allocated");
	var->data.i = ft_memalloc(sizeof(int) * W_WIDTH * W_HEIGHT);
	display_error(!var->data.i, "error: memmory is not allocated");
}

static void	ft_fractal_init(t_var *var)
{
	var->mode = 1;
	var->move = 1;
	var->ms.pressed = 0;
	var->scale = 1;
	var->iter = 100;
	var->f.x_min = -2;
	var->f.y_min = -2;
	var->f.x_max = 2;
	var->f.y_max = 2;
	var->f.offx = 0;
	var->f.offy = 0;
	var->ms.c_x = W_WIDTH / 2;
	var->ms.c_y = W_HEIGHT / 2;
	if (var->f.name == 2)
	{
		var->cx.re = 0.;
		var->cx.im = 0.;
	}
}

void		init(t_var *var)
{
	ft_window_init(var);
	ft_img_init(var);
	ft_ocl_init(var);
	ft_data_init(var);
	ft_fractal_init(var);
}
