/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_char.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 14:12:06 by lrobert      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 01:22:15 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../include/libft.h"

int		ft_display_char(printf_tab *tpf)
{
	char	text;
	int		nbspace;

	text = va_arg(tpf->ap, int);
	if (tpf->width > 0)
		nbspace = tpf->width - 1;
	else
		nbspace = 0;
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', nbspace, 1);
		ft_putchar_fd(text, 1);
	}
	else
	{
		ft_putchar_fd(text, 1);
		ft_putnchar_fd(' ', nbspace, 1);
	}
	tpf->length += nbspace + 1;
	return (tpf->length);
}
