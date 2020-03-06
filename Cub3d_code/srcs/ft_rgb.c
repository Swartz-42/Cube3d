/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:45:10 by aducas            #+#    #+#             */
/*   Updated: 2020/03/06 05:46:36 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rgb_roof(t_reglage *reglage, char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	reglage->cielr = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	reglage->cielg = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	reglage->cielb = ft_atoi(line + ++i);
}

void	ft_rgb_floor(t_reglage *reglage, char *line)
{
	int	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	reglage->solr = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		i++;
	reglage->solg = ft_atoi(line + ++i);
	while (ft_isdigit(line[i]))
		i++;
	reglage->solb = ft_atoi(line + ++i);
}

void	ft_rgb(char *line, t_reglage *reglage)
{
	if (line[0] == 'C')
		ft_rgb_roof(reglage, line);
	else
		ft_rgb_floor(reglage, line);
}
