/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:18:45 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:27:26 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_printf(const char *text, ...)
{
	int			i;
	printf_tab	tpf;
	char		*str;

	i = 0;
	va_start(tpf.ap, text);
	tpf.length = 0;
	str = (char *)text;
	while (text[i] != '\0')
	{
		if (text[i] == '%')
		{
			ft_init(&tpf);
			i++;
			i = i + ft_parse(&tpf, str + i);
		}
		else
		{
			ft_putchar_fd(text[i], 1);
			tpf.length++;
			i++;
		}
	}
	va_end(tpf.ap);
	return (tpf.length);
}
