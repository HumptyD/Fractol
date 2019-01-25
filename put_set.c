/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:25:34 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 15:36:51 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_var *var, int x, int y)
{
	int		n;
	double	temp;

	n = -1;
	var->cx.re = (((double)x / W_WIDTH) * (var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->cx.im = (((double)y / W_HEIGHT) * (var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
	var->cx.zre = 0;
	var->cx.zim = 0;
	while (++n < var->iter && var->cx.zre * var->cx.zre +
			var->cx.zim * var->cx.zim < 4)
	{
		temp = var->cx.zre;
		var->cx.zre = var->cx.zre * var->cx.zre -
			var->cx.zim * var->cx.zim + var->cx.re;
		var->cx.zim = 2 * temp * var->cx.zim + var->cx.im;
	}
	set_pixel(var, x, y, get_color(n, var));
}

void	burningship(t_var *var, int x, int y)
{
	int		n;
	double	temp;

	n = -1;
	var->cx.re = (((double)x / W_WIDTH) * (var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->cx.im = (((double)y / W_HEIGHT) * (var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
	var->cx.zre = 0;
	var->cx.zim = 0;
	while (++n < var->iter && var->cx.zre * var->cx.zre +
			var->cx.zim * var->cx.zim < 4)
	{
		temp = var->cx.zre;
		var->cx.zre = fabs(var->cx.zre * var->cx.zre -
			var->cx.zim * var->cx.zim + var->cx.re);
		var->cx.zim = fabs(2 * temp * var->cx.zim + var->cx.im);
	}
	set_pixel(var, x, y, get_color(n, var));
}

void	julia(t_var *var, int x, int y)
{
	int		n;
	double	temp;

	n = -1;
	var->cx.zre = (((double)x / W_WIDTH) * (var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->cx.zim = (((double)y / W_HEIGHT) * (var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
	while (++n < var->iter && var->cx.zre * var->cx.zre +
			var->cx.zim * var->cx.zim < 4)
	{
		temp = var->cx.zre;
		var->cx.zre = var->cx.zre * var->cx.zre -
			var->cx.zim * var->cx.zim + var->cx.re;
		var->cx.zim = 2 * temp * var->cx.zim + var->cx.im;
	}
	set_pixel(var, x, y, get_color(n, var));
}

void	mandel_flower(t_var *var, int x, int y)
{
	int		n;
	double	temp;
	double	ri;

	n = -1;
	var->cx.re = (((double)x / W_WIDTH) * (var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->cx.im = (((double)y / W_HEIGHT) * (var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
	var->cx.zre = 0;
	var->cx.zim = 0;
	ri = 0;
	while (++n < var->iter && ri < 4)
	{
		temp = var->cx.zre;
		var->cx.zre = pow(var->cx.zre, 6) - (15 * pow(var->cx.zre, 4) *
			pow(var->cx.zim, 2)) + (15 * pow(var->cx.zre, 2) *
			pow(var->cx.zim, 4)) - pow(var->cx.zim, 6) + var->cx.im;
		var->cx.zim = (6 * pow(temp, 5) * var->cx.zim - 20 * pow(temp, 3) *
			pow(var->cx.zim, 3) + 6 * temp * pow(var->cx.zim, 5)) + var->cx.re;
		ri = pow(var->cx.zre, 6) + pow(var->cx.zim, 6);
	}
	set_pixel(var, x, y, get_color(n, var));
}

void	*put_set(void *tab)
{
	t_var	*var;
	int		temp;

	var = (t_var *)tab;
	var->x = 0;
	temp = var->y;
	while (var->x < W_WIDTH)
	{
		var->y = temp;
		while (var->y < var->y_max)
		{
			if (var->f.name == 1)
				mandelbrot(var, var->x, var->y);
			else if (var->f.name == 2)
				julia(var, var->x, var->y);
			else if (var->f.name == 3)
				burningship(var, var->x, var->y);
			else if (var->f.name == 4)
				mandel_flower(var, var->x, var->y);
			var->y++;
		}
		var->x++;
	}
	return (tab);
}
