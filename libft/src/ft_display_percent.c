/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_percent.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 13:08:41 by lrobert      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 01:19:56 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_display_percent(printf_tab *tpf)
{
	int	nbspace;

	if (tpf->width > 0)
		nbspace = tpf->width - 1;
	else
		nbspace = tpf->width;
	tpf->length += nbspace + 1;
	if (nbspace < 0)
		nbspace = 0;
	if (!tpf->fminus)
	{
		if (tpf->fzero)
			ft_putnchar_fd('0', nbspace, 1);
		else
			ft_putnchar_fd(' ', nbspace, 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_putnchar_fd(' ', nbspace, 1);
	}
	return (tpf->length);
}
