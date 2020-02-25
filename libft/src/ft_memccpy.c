/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:38:17 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:38:18 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			d[i] = (unsigned char)c;
			dst = dst + i + 1;
			return (dst);
		}
		d[i] = s[i];
		i++;
	}
	return (0);
}
