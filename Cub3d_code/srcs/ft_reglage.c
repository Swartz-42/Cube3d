/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reglage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:49:16 by aducas            #+#    #+#             */
/*   Updated: 2020/03/06 06:50:21 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_reglage(t_reglage *reglage)
{
	reglage->x = 0;
	reglage->y = 0;
	reglage->textno = ft_strdup("");
	reglage->textso = ft_strdup("");
	reglage->textwe = ft_strdup("");
	reglage->textea = ft_strdup("");
	reglage->sprite = ft_strdup("");
	reglage->solr = 0;
	reglage->solg = 0;
	reglage->solb = 0;
	reglage->cielr = 0;
	reglage->cielg = 0;
	reglage->cielb = 0;
	reglage->map = ft_strdup("");
}

void	resolution(char *line, t_reglage *reglage)
{
	int i;

	i = 0;
	reglage->x = ft_atoi(line + 1);
	i = ft_strlen(line);
	while (!ft_isdigit(line[i]))
		i--;
	while (ft_isdigit(line[i]))
		i--;
	reglage->y = ft_atoi(line + i);
}

void	ft_parce(char *line, t_reglage *reglage)
{
	if (line[0] == 'R')
		resolution(line, reglage);
	else if (line[0] == 'N' && line[1] == 'O')
		reglage->textno = ft_strdup(line + 3);
	else if (line[0] == 'S' && line[1] == 'O')
		reglage->textso = ft_strdup(line + 3);
	else if (line[0] == 'W' && line[1] == 'E')
		reglage->textwe = ft_strdup(line + 3);
	else if (line[0] == 'E' && line[1] == 'A')
		reglage->textea = ft_strdup(line + 3);
	else if (line[0] == 'S')
		reglage->sprite = ft_strdup(line + 2);
	else if (line[0] == 'F' || line[0] == 'C')
		ft_rgb(line, reglage);
	else
		ft_printf("ERROR\nErreur dans un parametre\n");
}

int		ft_read_line(int fd, char *line, t_reglage *reglage)
{
	int ret;

	ret = get_next_line(fd, &line);
	if (ft_comp(line[0], "RNSWEFC"))
		ft_parce(line, reglage);
	else if (line[0] == '1' && line[ft_strlen(line) - 1] == '1')
	{
		reglage->map = ft_strjoin(reglage->map, ft_strjoin(line, "\n"));
	}
	else if ((line[0] != '1' || line[ft_strlen(line) - 1] != '1') &&
			(read(fd, line, 0) >= 1))
	{
		ft_printf("ERROR\nErreur map\n");
		return (-1);
	}
	line = 0;
	if (ret == 0)
		return (0);
	return (1);
}
