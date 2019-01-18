/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:18:45 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/18 19:03:24 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_var	var;

	display_error(argc != 2,
			"usage: ./fractol \"mandelbrot\", \"julia\", \"burningship\"");
	ft_fractal_name_init(&var, argv[1]);
	init(&var);
	ft_pthread(&var);
	mlx_hook(var.win, 2, 0, keyboard, &var);
	mlx_hook(var.win, 4, 0, mouse_press, &var);
	mlx_hook(var.win, 5, 0, mouse_release, &var);
	mlx_hook(var.win, 6, 0, mouse_move, &var);
	mlx_loop(var.mlx);
	return (0);
}
