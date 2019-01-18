#pragma OPENCL EXTENSION cl_khr_fp64 : enable

__kernel void	bship_calc(__global double *z,
					__global double *c, __global int *i, __global int *iter)
{
	int		it;
	int		id;
	double	ztemp[2];
	double	ctemp[2];
	double	temp_re;
	double	temp_im;

	id = get_global_id(0);
	id *= 2;
	it = -1;
	ztemp[0] = z[id];
	ztemp[1] = z[id + 1];
	ctemp[0] = c[id];
	ctemp[1] = c[id + 1];
	while (++it < *iter && ztemp[0] * ztemp[0] + ztemp[1] * ztemp[1] < 4)
	{
		temp_re = ztemp[0];
		temp_im = ztemp[1];
		ztemp[0] = fabs(temp_re * temp_re - temp_im * temp_im + ctemp[0]);
		ztemp[1] = fabs(2 * temp_re * temp_im + ctemp[1]);
	}
	z[id] = ztemp[0];
	z[id + 1] = ztemp[1];
	i[id / 2] = it;
}
