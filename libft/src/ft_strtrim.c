/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:22:30 by aducas            #+#    #+#             */
/*   Updated: 2020/02/19 14:01:11 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_cmp(char const *s1, char const *set)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static int		ft_rcmp(char const *s1, char const *set)
{
	int i;
	int j;

	i = ft_strlen(s1);
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;

	if (s1 == 0 || set == 0)
		return (0);
	if (ft_rcmp(s1, set) < ft_cmp(s1, set))
		return (ft_strdup(""));
	i = (ft_rcmp(s1, set) - ft_cmp(s1, set));
	str = malloc(sizeof(char) * i);
	if (str == 0)
		return (str);
	return (ft_substr(s1, ft_cmp(s1, set), i));
}
