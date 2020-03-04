/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <abourbou@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 09:23:25 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 11:38:55 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*strcpy;

	i = 0;
	while (s1[i])
		i++;
	if ((strcpy = wrmalloc((i + 1) * sizeof(char))) == 0)
		return (0);
	j = 0;
	while (j <= i)
	{
		strcpy[j] = s1[j];
		j++;
	}
	return (strcpy);
}

/*
**	Copie jusqu'a n caractères + un \0
*/

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	i = 0;
	while (s1[i] && i < n)
		i++;
	if (!(str = wrmalloc(i + 1)))
		return (0);
	ft_strlcpy(str, s1, i + 1);
	return (str);
}
