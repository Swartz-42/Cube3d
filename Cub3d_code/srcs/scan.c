/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:55:44 by aducas            #+#    #+#             */
/*   Updated: 2020/12/14 16:34:09 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static float	shortest_distance(t_cub3d cub3d, float alpha)
{
	float	rh;
	float	rv;
	float	correct;

	rh = rayon_h(cub3d, alpha);
	rv = rayon_v(cub3d, alpha);
	correct = (rh <= rv) ? rh : rv;
	return (correct);
}

void			scan(t_cub3d *cub3d)
{
	int		x;
	float	cons;
	float	alpha;
	float	sd;
	float	projected_wall;

	x = 0;
	cub3d->config.deep = (cub3d->win.x / 2) / tan(FOV * M_PI / 180);
	alpha = cub3d->config.pov - ((FOV * M_PI / 180) / 2);
	cons = (FOV * M_PI / 180) / cub3d->win.x;
	while (x < cub3d->win.x)
	{
		if (alpha <= 0)
			alpha += 2 * M_PI;
		sd = shortest_distance(*cub3d, alpha);
		projected_wall = (BLOCK_SIZE / sd) * cub3d->config.deep;
		display_wall(x, projected_wall, *cub3d);
		alpha += cons;
		x++;
	}
}
