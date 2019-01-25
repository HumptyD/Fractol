#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void	mandel_flower_calc(__global double *z,
					__global double *c, __global int *i, __global int *iter)
{
	int		it;
	int		id;
	double	ztemp[2];
	double	ctemp[2];
	double	temp_re;
	double	temp_im;
	double	ri;

	id = get_global_id(0);
	id *= 2;
	it = -1;
	ztemp[0] = z[id];
	ztemp[1] = z[id + 1];
	ctemp[0] = c[id];
	ctemp[1] = c[id + 1];
	ri = 0;
	while (++it < *iter && ri < 4)
	{
		temp_re = ztemp[0];
		temp_im = ztemp[1];
		ztemp[0] = pow(temp_re, 6) - (15 * pow(temp_re, 4) * pow(temp_im, 2)) +
					(15 * pow(temp_re, 2) * pow(temp_im, 4)) - pow(temp_im, 6) + ctemp[1];
		ztemp[1] = (6 * pow(temp_re, 5) * temp_im - 20 * pow(temp_re, 3) *
					pow(temp_im, 3) + 6 * temp_re * pow(temp_im, 5)) + ctemp[0];
		ri = pow(ztemp[0], 6) + pow(ztemp[1], 6);
	}
	z[id] = ztemp[0];
	z[id + 1] = ztemp[1];
	i[id / 2] = it;
}
