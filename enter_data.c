/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:21:28 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/20 15:50:05 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mnd_bship_data(t_var *var, int re, int im)
{
	var->data.c[re] = (((double)var->x / W_WIDTH) *
			(var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->data.c[im] = (((double)var->y / W_HEIGHT) *
			(var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
	var->data.z[re] = 0;
	var->data.z[im] = 0;
}

void	julia_data(t_var *var, int re, int im)
{
	var->data.c[re] = var->cx.re;
	var->data.c[im] = var->cx.im;
	var->data.z[re] = (((double)var->x / W_WIDTH) *
			(var->f.x_max - var->f.x_min)) *
		var->scale + var->f.x_min - var->f.offx;
	var->data.z[im] = (((double)var->y / W_HEIGHT) *
			(var->f.y_max - var->f.y_min)) *
		var->scale + var->f.y_min - var->f.offy;
}

void	*ft_enter_data(void *tab)
{
	t_var	*var;
	int		temp;
	int		i;

	var = (t_var *)tab;
	var->x = 0;
	temp = var->y;
	while (var->x < W_WIDTH)
	{
		var->y = temp;
		while (var->y < var->y_max)
		{
			i = var->y * W_WIDTH + var->x;
			if (var->f.name == 1 || var->f.name == 3 || var->f.name == 4)
				mnd_bship_data(var, i * 2, i * 2 + 1);
			else if (var->f.name == 2)
				julia_data(var, i * 2, i * 2 + 1);
			var->y++;
		}
		var->x++;
	}
	return (tab);
}
