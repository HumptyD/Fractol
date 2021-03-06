/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:34:14 by jlucas-l          #+#    #+#             */
/*   Updated: 2019/01/25 16:12:45 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_read_cl(t_var *var)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	var->ocl.src = ft_strnew(0);
	fd = -1;
	if (var->f.name == 1 || var->f.name == 2)
		fd = open("mand_julia_calc.cl", O_RDONLY);
	else if (var->f.name == 3)
		fd = open("bship_calc.cl", O_RDONLY);
	else if (var->f.name == 4)
		fd = open("mandel_flower_calc.cl", O_RDONLY);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = var->ocl.src;
		var->ocl.src = ft_strjoin(var->ocl.src, buf);
		free(temp);
	}
	close(fd);
}

static void	ft_make_kernel(t_var *var)
{
	var->ocl.w_item = W_WIDTH * W_HEIGHT;
	var->ocl.program = clCreateProgramWithSource(var->ocl.context,
			1, (const char **)&var->ocl.src, NULL, &var->ocl.ret);
	var->ocl.ret = clBuildProgram(var->ocl.program, 1,
			&var->ocl.d_id, NULL, NULL, NULL);
	if (var->f.name == 1 || var->f.name == 2)
		var->ocl.kernel = clCreateKernel(var->ocl.program,
				"mand_julia_calc", &var->ocl.ret);
	else if (var->f.name == 3)
		var->ocl.kernel = clCreateKernel(var->ocl.program,
				"bship_calc", &var->ocl.ret);
	else if (var->f.name == 4)
		var->ocl.kernel = clCreateKernel(var->ocl.program,
				"mandel_flower_calc", &var->ocl.ret);
	clSetKernelArg(var->ocl.kernel, 0, sizeof(cl_mem), (void *)&var->ocl.zmem);
	clSetKernelArg(var->ocl.kernel, 1, sizeof(cl_mem), (void *)&var->ocl.cmem);
	clSetKernelArg(var->ocl.kernel, 2, sizeof(cl_mem), (void *)&var->ocl.imem);
	clSetKernelArg(var->ocl.kernel, 3, sizeof(cl_mem), (void *)&var->ocl.itmem);
}

void		ft_ocl_init(t_var *var)
{
	var->ocl.ret = clGetPlatformIDs(1, &var->ocl.p_id, &var->ocl.r_n_platforms);
	var->ocl.ret = clGetDeviceIDs(var->ocl.p_id, CL_DEVICE_TYPE_GPU,
			1, &var->ocl.d_id, &var->ocl.r_n_devices);
	var->ocl.context = clCreateContext(NULL, 1, &var->ocl.d_id, NULL,
			NULL, &var->ocl.ret);
	var->ocl.c_queue = clCreateCommandQueue(var->ocl.context,
			var->ocl.d_id, 0, &var->ocl.ret);
	var->ocl.zmem = clCreateBuffer(var->ocl.context, CL_MEM_READ_WRITE,
			W_WIDTH * W_HEIGHT * 2 * sizeof(cl_double), NULL, &var->ocl.ret);
	var->ocl.cmem = clCreateBuffer(var->ocl.context, CL_MEM_READ_WRITE,
			W_WIDTH * W_HEIGHT * 2 * sizeof(cl_double), NULL, &var->ocl.ret);
	var->ocl.imem = clCreateBuffer(var->ocl.context, CL_MEM_READ_WRITE,
			W_WIDTH * W_HEIGHT * sizeof(cl_int), NULL, &var->ocl.ret);
	var->ocl.itmem = clCreateBuffer(var->ocl.context, CL_MEM_READ_ONLY,
			sizeof(cl_int), NULL, &var->ocl.ret);
	ft_read_cl(var);
	ft_make_kernel(var);
}
