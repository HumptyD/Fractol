/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:18:45 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/12 17:48:39 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int argc, char **argv)
{
	t_var	var;

	display_error(argc != 2, "error: wrong amount of arguments");
	init(&var);
	init_fractal(&var, argv[1]);
	thread(&var);
	mlx_hook(var.win, 2, 0, keyboard, &var);
	mlx_hook(var.win, 4, 0, mouse_press, &var);
	mlx_hook(var.win, 5, 0, mouse_release, &var);
	mlx_hook(var.win, 6, 0, mouse_move, &var);
	mlx_loop(var.mlx);
	return (0);
}
