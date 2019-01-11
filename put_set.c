/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:25:34 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 21:04:21 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_var *var, int x, int y)
{
	int		n;
	long double	temp;

	n = -1;
	var->cx.re = var->mnd.xs + x / var->opt.scale;
	var->cx.im = var->mnd.ys + y / var->opt.scale;
	var->cx.zre = 0;
	var->cx.zim = 0;
	while (++n < var->opt.iter)
	{
		temp = var->cx.zre;
		var->cx.zre = var->cx.zre * var->cx.zre -
			var->cx.zim * var->cx.zim + var->cx.re;
		var->cx.zim = 2 * temp * var->cx.zim + var->cx.im;
		if (var->cx.zre + var->cx.zim > 16)
			break ;
	}
	set_pixel(var, x, y, n == var->opt.iter ? 0 : n * 265);
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
			if (!ft_strcmp(var->fractal, "mandelbrot"))
				mandelbrot(var, var->x, var->y);
			var->y++;
		}
		var->x++;
	}
	return (tab);
}
