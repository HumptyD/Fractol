/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:11:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 15:43:06 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(t_var *var, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	*(int *)(var->img.ptr + (x + y * W_WIDTH) * var->img.bpp) = color;
}

void	*ft_fill_img(void *tab)
{
	t_var	*var;
	int		temp;
	int		id;

	var = (t_var *)tab;
	var->x = 0;
	temp = var->y;
	while (var->x < W_WIDTH)
	{
		var->y = temp;
		while (var->y < var->y_max)
		{
			id = var->y * W_WIDTH + var->x;
			set_pixel(var, var->x, var->y, get_color(var->data.i[id], var));
			var->y++;
		}
		var->x++;
	}
	return (tab);
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, W_WIDTH * W_HEIGHT * img->bpp);
}
