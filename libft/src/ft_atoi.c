/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:30:27 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:30:48 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	signe;
	long	chiffre;

	chiffre = 0;
	signe = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = -signe;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		chiffre = chiffre * 10 + str[i] - '0';
		i++;
	}
	return (chiffre * signe);
}
