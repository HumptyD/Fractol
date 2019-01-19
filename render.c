/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:17:10 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/19 19:51:51 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pthread_data(t_var *var)
{
	t_var		tab[THREAD_N];
	pthread_t	t[THREAD_N];
	int			i;

	i = -1;
	while (++i < THREAD_N)
	{
		ft_memcpy((void *)&tab[i], (void *)var, sizeof(t_var));
		tab[i].y = W_HEIGHT / THREAD_N * i;
		tab[i].y_max = W_HEIGHT / THREAD_N * (i + 1);
		pthread_create(&t[i], NULL, ft_enter_data, &tab[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}

static void	ft_ocl_exe(t_var *var)
{
	int		s;

	s = W_WIDTH * W_HEIGHT;
	clEnqueueWriteBuffer(var->ocl.c_queue, var->ocl.zmem, CL_TRUE, 0,
			sizeof(cl_double) * s * 2, var->data.z, 0, NULL, NULL);
	clEnqueueWriteBuffer(var->ocl.c_queue, var->ocl.cmem, CL_TRUE, 0,
			sizeof(cl_double) * s * 2, var->data.c, 0, NULL, NULL);
	clEnqueueWriteBuffer(var->ocl.c_queue, var->ocl.imem, CL_TRUE, 0,
			sizeof(cl_int) * s, var->data.i, 0, NULL, NULL);
	clEnqueueWriteBuffer(var->ocl.c_queue, var->ocl.itmem, CL_TRUE, 0,
			sizeof(cl_int), &var->iter, 0, NULL, NULL);
	clEnqueueNDRangeKernel(var->ocl.c_queue, var->ocl.kernel, 1, NULL,
			&var->ocl.w_item, NULL, 0, NULL, NULL);
	clEnqueueReadBuffer(var->ocl.c_queue, var->ocl.imem, CL_TRUE, 0,
			sizeof(cl_int) * var->ocl.w_item, var->data.i, 0, NULL, NULL);
}

static void	ft_pthread_img(t_var *var)
{
	t_var		tab[THREAD_N];
	pthread_t	t[THREAD_N];
	int			i;

	i = -1;
	while (++i < THREAD_N)
	{
		ft_memcpy((void *)&tab[i], (void *)var, sizeof(t_var));
		tab[i].y = W_HEIGHT / THREAD_N * i;
		tab[i].y_max = W_HEIGHT / THREAD_N * (i + 1);
		pthread_create(&t[i], NULL, ft_fill_img, &tab[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}

static void	ft_pthread_render(t_var *var)
{
	t_var		tab[THREAD_N];
	pthread_t	t[THREAD_N];
	int			i;

	clear_image(&var->img);
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
	mlx_put_image_to_window(var->mlx, var->win, var->img.image, 0, 0);
}

void		ft_render(t_var *var)
{
	if (var->mode && var->f.name != 4)
	{
		ft_pthread_data(var);
		ft_ocl_exe(var);
		ft_pthread_img(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img.image, 0, 0);
	}
	else
		ft_pthread_render(var);
}
