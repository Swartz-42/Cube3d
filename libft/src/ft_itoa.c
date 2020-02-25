/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:34:40 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 14:34:41 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char	*ft_swap(char *str)
{
	char	tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (str[i])
		i++;
	while (a < i)
	{
		tmp = str[a];
		str[a] = str[i - 1];
		str[i - 1] = tmp;
		a++;
		i--;
	}
	return (str);
}

static	int		cpt_n(long int n)
{
	int cpt;

	cpt = 0;
	if (n <= 0)
		cpt++;
	while (n)
	{
		n = n / 10;
		cpt++;
	}
	return (cpt);
}

char			*ft_itoa(long int n)
{
	int			i;
	int			neg;
	char		*str;

	if (!(str = malloc(sizeof(char) * (cpt_n(n) + 1))))
		return (0);
	i = 0;
	if (n == 0)
		str[i++] = '0';
	neg = (n < 0) ? 1 : 0;
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		str[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[i++] = '-';
	str[i++] = '\0';
	return (ft_swap(str));
}
