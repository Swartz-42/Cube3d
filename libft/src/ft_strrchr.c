/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:48:04 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:01:05 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		taille;
	char	*st;

	taille = ft_strlen(s);
	st = (char *)s;
	while (st[taille] != c && taille > 0)
		taille--;
	if (st[taille] == c)
		return (st + taille);
	return (0);
}
