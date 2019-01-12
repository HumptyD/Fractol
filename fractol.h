/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:08:26 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/12 20:49:23 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define W_WIDTH 720
# define W_HEIGHT 720
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

typedef struct	s_options
{
	double		scale;
	int			iter;
}				t_options;

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
}				t_fractal;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_options	opt;
	t_complex	cx;
	t_fractal	f;
	t_mouse		ms;
	int			x;
	int			y;
	int			y_max;
}				t_var;

void			init(t_var *var);
void			init_fractal(t_var *var, char *name);
void			*put_set(void *tab);
void			display_error(int cond, char *str);
void			set_pixel(t_var *var, int x, int y, int color);
int				keyboard(int key, t_var *var);
int				mouse_press(int button, int x, int y, t_var *var);
int				mouse_release(int button, int x, int y, t_var *var);
int				mouse_move(int x, int y, t_var *var);
void			clear_image(t_img *img);
void			thread(t_var *var);
int				get_color(int n);

#endif
