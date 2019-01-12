/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:17:10 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/12 21:38:21 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thread(t_var *var)
{
	t_var		tab[THREAD_N];
	pthread_t	t[THREAD_N];
	int			i;

	clear_image(var->img);
	i = -1;
	while (++i < THREAD_N)
	{
		ft_memcpy((void *)&tab[i], (void *)var, sizeof(t_var));
		tab[i].y = W_HEIGHT / THREAD_N * i;
		tab[i].y_max = W_HEIGHT / THREAD_N * (i + 1);
		pthread_create(&t[i], NULL, put_set, &tab[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(var->mlx, var->win, var->img->image, 0, 0);
}
