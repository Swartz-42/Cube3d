/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:52:14 by gbendjaf          #+#    #+#             */
/*   Updated: 2020/02/19 15:47:39 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_init(printf_tab *tpf)
{
	tpf->fminus = FALSE;
	tpf->fzero = FALSE;
	tpf->fprecision = FALSE;
	tpf->width = 0;
	tpf->valprec = 0;
	tpf->nbspace = 0;
	tpf->nbzero = 0;
}
