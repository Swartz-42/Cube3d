/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cpy_line.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: swartz <swartz@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/24 15:42:57 by swartz       #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 15:47:45 by swartz      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

int		cpy_line(char *str, char **line, int i_rc)
{
	if (i_rc > 0)
		(*line) = ft_substr(str, 0, i_rc - 1);
	else
		(*line) = ft_substr(str, 0, ft_strlen(str));
	if (!(*line))
		return (-1);
	return (0);
}
