/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:26:43 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:38:37 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c_dst;
	char	*c_src;

	if (!src && !dst)
		return (0);
	c_dst = (char *)dst;
	c_src = (char *)src;
	if (c_src >= c_dst)
		return (ft_memcpy(dst, src, len));
	c_dst += len;
	c_src += len;
	while (len--)
		*--c_dst = *--c_src;
	return (dst);
}
