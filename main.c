/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 15:18:45 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 20:45:22 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int argc, char **argv)
{
	t_var	var;

	display_error(argc != 2, "error: wrong amount of arguments");
	init_var(&var, argv[1]);
	init_image(&var);
	thread(&var);
	mlx_hook(var.win, 2, 0, keyboard, &var);
	mlx_hook(var.win, 4, 0, mouse_press, &var);
	mlx_loop(var.mlx);
	return (0);
}
