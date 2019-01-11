/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:08:26 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/11 21:06:09 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <pthread.h>

# define W_WIDTH 1089
# define W_HEIGHT 720
# define THREAD_N 16

typedef struct	s_complex
{
	long double		re;
	long double		im;
	long double		zre;
	long double		zim;
}				t_complex;

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

typedef	struct	s_mndlbrt
{
	double		xs;
	double		ys;
}				t_mndlbrt;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	char		*fractal;
	t_img		*img;
	t_options	opt;
	t_complex	cx;
	t_mndlbrt	mnd;
	int			x;
	int			y;
	int			y_max;
}				t_var;

void			init_image(t_var *var);
void			init_var(t_var *var, char *name);
void			*put_set(void *tab);
void			display_error(int cond, char *str);
void			set_pixel(t_var *var, int x, int y, int color);
int				keyboard(int key, t_var *var);
int				mouse_press(int button, int x, int y, t_var *var);
void			clear_image(t_img *img);
void			thread(t_var *var);

#endif
