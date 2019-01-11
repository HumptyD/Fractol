/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:11:00 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 20:21:00 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel(t_var *var, int x, int y, int color)
{
	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	*(int *)(var->img->ptr + (x + y * W_WIDTH) * var->img->bpp) = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, W_WIDTH * W_HEIGHT * img->bpp);
}
