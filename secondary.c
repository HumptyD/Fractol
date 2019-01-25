/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:44:59 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 16:16:33 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	display_error(int cond, char *str)
{
	if (cond)
	{
		ft_putendl(str);
		exit(0);
	}
}

int		get_color(int n, t_var *var)
{
	double	p;

	if (n == var->iter)
		return (0x000000);
	p = (double)n / var->iter;
	if (p >= 0 && p < 0.2)
		return (n % 100 * 0x2F2472);
	else if (p >= 0.2 && p < 0.4)
		return (n % 100 * 0x6ED7EF);
	else if (p >= 0.4 && p < 0.6)
		return (n % 100 * 0x6d68d1);
	else if (p >= 0.6 && p < 0.8)
		return (n % 100 * 0x6EEFAC);
	else
		return (n % 100 * 0xCFEF6E);
}
