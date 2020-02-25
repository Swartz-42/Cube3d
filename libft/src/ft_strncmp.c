/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:45:37 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:00:16 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*st1;
	const unsigned char	*st2;
	size_t				i;

	st1 = (const unsigned char *)s1;
	st2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && (*(st1 + i) || *(st2 + i)))
	{
		if (*(st1 + i) != *(st2 + i))
			return (*(st1 + i) - *(st2 + i));
		i++;
	}
	return (0);
}
