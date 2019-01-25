/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:18:45 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/20 15:57:17 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define USG "usage: ./fractal [name: {mandelbrot, julia, burningship, flower}]"

static int	ft_fractal_name(t_var *var, char *name)
{
	var->f.set_name = name;
	if (!ft_strcmp(name, "mandelbrot"))
		var->f.name = 1;
	else if (!ft_strcmp(name, "julia"))
		var->f.name = 2;
	else if (!ft_strcmp(name, "burningship"))
		var->f.name = 3;
	else if (!ft_strcmp(name, "flower"))
		var->f.name = 4;
	else
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_var	var;

	display_error(argc != 2, USG);
	display_error(ft_fractal_name(&var, argv[1]), USG);
	init(&var);
	ft_render(&var);
	mlx_hook(var.win, 2, 0, keyboard, &var);
	mlx_hook(var.win, 4, 0, mouse_press, &var);
	mlx_hook(var.win, 5, 0, mouse_release, &var);
	mlx_hook(var.win, 6, 0, mouse_move, &var);
	mlx_loop(var.mlx);
	return (0);
}
