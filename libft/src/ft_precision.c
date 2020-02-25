/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:03:22 by lrobert           #+#    #+#             */
/*   Updated: 2020/02/19 16:46:16 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_precision_neg(printf_tab *tpf, int argsize)
{
	if (tpf->valprec >= argsize)
	{
		tpf->nbzero = (tpf->valprec - argsize) + 1;
		tpf->nbspace -= tpf->nbzero;
	}
	else
		tpf->nbzero = 0;
	if (tpf->nbspace < 0)
		tpf->nbspace = 0;
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
}

void	ft_precision_pos(printf_tab *tpf, int val, int argsize)
{
	if (tpf->valprec > argsize)
	{
		if (tpf->width > tpf->valprec)
			tpf->nbspace = tpf->width - tpf->valprec;
		else
			tpf->nbspace -= tpf->nbzero;
		tpf->nbzero = tpf->valprec - argsize;
	}
	if (tpf->nbspace < 0)
		tpf->nbspace = 0;
	if (tpf->valprec >= tpf->width)
		tpf->nbspace = 0;
	else if (tpf->valprec <= argsize)
		tpf->nbzero = 0;
	else
	{
		ft_display(tpf, val, 0);
		return ;
	}
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	ft_display(tpf, val, 0);
}

void	ft_precision_ui(printf_tab *tpf, int val, int argsize)
{
	if (tpf->valprec > argsize)
	{
		if (tpf->width > tpf->valprec)
			tpf->nbspace = tpf->width - tpf->valprec;
		else
			tpf->nbspace -= tpf->nbzero;
		tpf->nbzero = tpf->valprec - argsize;
	}
	if (tpf->nbspace < 0)
		tpf->nbspace = 0;
	if (tpf->valprec >= tpf->width)
		tpf->nbspace = 0;
	else if (tpf->valprec <= argsize)
		tpf->nbzero = 0;
	else
	{
		ft_display_ui(tpf, val);
		return ;
	}
	if (tpf->width > argsize + tpf->nbzero)
		tpf->nbspace = tpf->width - (argsize + tpf->nbzero);
	ft_display_ui(tpf, val);
}
