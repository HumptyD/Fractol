/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:41:18 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/18 18:54:35 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int x, int y, t_var *var, double z)
{
	double	w;
	double	h;
	double	w1;
	double	h1;

	w = (var->f.x_max - var->f.x_min) * var->scale;
	h = (var->f.y_max - var->f.y_min) * var->scale;
	w1 = (var->f.x_max - var->f.y_min) * var->scale * z;
	h1 = (var->f.y_max - var->f.y_min) * var->scale * z;
	var->scale *= z;
	var->f.offx += ((double)x / W_WIDTH) * (w1 - w);
	var->f.offy += ((double)y / W_HEIGHT) * (h1 - h);
	(z < 1) ? var->iter++ : var->iter--;
}

int			keyboard(int key, t_var *var)
{
	clear_image(&var->img);
	key == 53 ? exit(0) : 0;
	put_set(var);
	return (0);
}

int			mouse_release(int button, int x, int y, t_var *var)
{
	(void)button;
	(void)x;
	(void)y;
	var->ms.pressed = 0;
	return (0);
}

int			mouse_press(int button, int x, int y, t_var *var)
{
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		if (button == 1)
		{
			var->ms.c_x = x;
			var->ms.c_y = y;
			var->ms.pressed = 1;
		}
		if (button == 2)
		{
			var->ms.c_x = x;
			var->ms.c_y = y;
			var->ms.pressed = 2;
		}
		if (button == 5)
			zoom(x, y, var, 0.9);
		if (button == 4)
			zoom(x, y, var, 1.1);
		if (button == 4 || button == 5)
			ft_pthread(var);
	}
	return (0);
}

int			mouse_move(int x, int y, t_var *var)
{
	double	w;
	double	h;

	var->ms.p_x = var->ms.c_x;
	var->ms.p_y = var->ms.c_y;
	var->ms.c_x = x;
	var->ms.c_y = y;
	if (var->ms.pressed == 1 && var->f.name == 2)
	{
		w = (var->f.x_max - var->f.x_min) * var->scale;
		h = (var->f.y_max - var->f.y_min) * var->scale;
		var->cx.re -= (double)(var->ms.p_x - var->ms.c_x) / W_WIDTH * w;
		var->cx.im -= (double)(var->ms.p_y - var->ms.c_y) / W_HEIGHT * h;
	}
	if (var->ms.pressed == 2)
	{
		w = (var->f.x_max - var->f.x_min) * var->scale;
		h = (var->f.y_max - var->f.y_min) * var->scale;
		var->f.offx -= (double)(var->ms.p_x - var->ms.c_x) / W_WIDTH * w;
		var->f.offy -= (double)(var->ms.p_y - var->ms.c_y) / W_HEIGHT * h;
	}
	if (var->ms.pressed)
		ft_pthread(var);
	return (0);
}
