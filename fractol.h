/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:08:26 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 15:37:09 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>
# include <OpenCL/opencl.h>
# include <stdio.h>

# define W_WIDTH 1000
# define W_HEIGHT 1000
# define THREAD_N 16

typedef struct	s_complex
{
	double		re;
	double		im;
	double		zre;
	double		zim;
}				t_complex;

typedef struct	s_mouse
{
	double		p_x;
	double		p_y;
	double		c_x;
	double		c_y;
	int			pressed;
}				t_mouse;

typedef struct	s_img
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_fractal
{
	double		x_min;
	double		y_min;
	double		x_max;
	double		y_max;
	double		offx;
	double		offy;
	int			name;
	char		*set_name;
}				t_fractal;

typedef struct	s_arr_ocl
{
	double		*z;
	double		*c;
	int			*i;
}				t_arr_ocl;

typedef struct	s_ocl
{
	cl_int				ret;
	cl_platform_id		p_id;
	cl_uint				r_n_platforms;
	cl_device_id		d_id;
	cl_uint				r_n_devices;
	cl_context			context;
	cl_command_queue	c_queue;
	cl_mem				zmem;
	cl_mem				cmem;
	cl_mem				imem;
	cl_mem				itmem;
	cl_program			program;
	char				*src;
	cl_kernel			kernel;
	size_t				w_item;
}				t_ocl;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_complex	cx;
	t_fractal	f;
	t_mouse		ms;
	t_arr_ocl	data;
	t_ocl		ocl;
	int			mode;
	int			move;
	int			x;
	int			y;
	int			y_max;
	int			iter;
	double		scale;
}				t_var;

void			init(t_var *var);
void			*put_set(void *tab);
void			display_error(int cond, char *str);
void			set_pixel(t_var *var, int x, int y, int color);
int				keyboard(int key, t_var *var);
int				mouse_press(int button, int x, int y, t_var *var);
int				mouse_release(int button, int x, int y, t_var *var);
int				mouse_move(int x, int y, t_var *var);
void			clear_image(t_img *img);
void			ft_render(t_var *var);
int				get_color(int n, t_var *var);
void			*ft_enter_data(void *tab);
void			*ft_fill_img(void *tab);
void			ft_ocl_init(t_var *var);

#endif
