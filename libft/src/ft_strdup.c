/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:54:27 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 13:59:26 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i++;
	if (!(s2 = malloc(i * sizeof(char))))
		return (0);
	while (i--)
		s2[i] = s1[i];
	s2[0] = s1[0];
	return (s2);
}
