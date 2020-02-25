/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:12:57 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:00:58 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n_len;

	if (!*needle)
		return ((char *)haystack);
	n_len = ft_strlen(needle);
	while (*haystack && n_len <= len)
	{
		if (*haystack == *needle && ft_memcmp(needle, haystack, n_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
