/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:38:07 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:38:09 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*chr;
	unsigned int	a;

	chr = (unsigned char *)str;
	a = 0;
	while (a < n)
	{
		if (chr[a] == (unsigned char)c)
			return ((void *)&chr[a]);
		a++;
	}
	return (0);
}
