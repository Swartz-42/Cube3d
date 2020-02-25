/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:36:21 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:36:23 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				cmp;

	i = 0;
	cmp = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (cmp == 0 && i < n)
	{
		cmp = str1[i] - str2[i];
		i++;
	}
	return (cmp);
}
