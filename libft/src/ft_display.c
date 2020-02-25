/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 17:40:10 by lrobert      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 01:20:04 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_display_pos(printf_tab *tpf, long int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(val, 1);
	}
	else
	{
		ft_putnbr_fd(val, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

static void	ft_display_neg(printf_tab *tpf, long int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(-val, 1);
	}
	else
	{
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_fd(-val, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display_x(printf_tab *tpf, long val, char *base)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, base);
	}
	else
	{
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, base);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display_ui(printf_tab *tpf, unsigned int val)
{
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnbr_base(val, BASE10);
	}
	else
	{
		ft_putnbr_base(val, BASE10);
		ft_putnchar_fd('0', tpf->nbzero, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
}

void		ft_display(printf_tab *tpf, int val, int sign)
{
	if (sign == 0)
		ft_display_pos(tpf, val);
	else
		ft_display_neg(tpf, val);
}
