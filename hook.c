/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:41:18 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 20:20:40 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int x, int y, t_var *var, double z)
{
	var->mnd.xs = (x / var->opt.scale + var->mnd.xs)
		- (x / (var->opt.scale * z));
	var->mnd.ys = (y / var->opt.scale + var->mnd.ys)
		- (y / (var->opt.scale * z));
	var->opt.scale *= z;
	var->opt.iter++;
}

int			keyboard(int key, t_var *var)
{
	clear_image(var->img);
	key == 53 ? exit(0) : 0;
	put_set(var);
	return (0);
}

int			mouse_press(int button, int x, int y, t_var *var)
{
	clear_image(var->img);
	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		if (button == 5)
			zoom(x, y, var, 1.1);
		if (button == 4)
			zoom(x, y, var, 0.9);
		if (button == 4 || button == 5)
			thread(var);
	}
	return (0);
}
