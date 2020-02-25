/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display_str.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/27 14:51:35 by lrobert      #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 01:19:59 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_prec_arglen(printf_tab *tpf, int argsize)
{
	int	arglen;

	if (tpf->fprecision == TRUE && tpf->valprec < argsize)
	{
		if (tpf->valprec == 0)
			arglen = 0;
		else
			arglen = tpf->valprec;
	}
	else
		arglen = argsize;
	return (arglen);
}

int			ft_display_str(printf_tab *tpf)
{
	int		argsize;
	int		arglen;
	char	*text;

	if (!(text = va_arg(tpf->ap, char *)))
		text = "(null)";
	argsize = ft_strlen(text);
	arglen = ft_prec_arglen(tpf, argsize);
	if (tpf->valprec < tpf->width && tpf->fprecision == TRUE)
		tpf->nbspace = tpf->width - tpf->valprec;
	if (tpf->width >= arglen)
		tpf->nbspace = tpf->width - arglen;
	if (tpf->fminus == FALSE)
	{
		ft_putnchar_fd(' ', tpf->nbspace, 1);
		ft_putnstr_fd(text, arglen, 1);
	}
	else
	{
		ft_putnstr_fd(text, arglen, 1);
		ft_putnchar_fd(' ', tpf->nbspace, 1);
	}
	tpf->length += arglen + tpf->nbspace;
	return (tpf->length);
}
