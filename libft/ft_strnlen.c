/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:55:09 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/19 20:56:27 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnlen(const char *s, int n)
{
	int	i;

	i = 0;
	while (s[i] && i < n)
		i++;
	return (i);
}
