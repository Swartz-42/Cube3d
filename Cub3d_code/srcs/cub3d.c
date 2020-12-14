/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:02:00 by aducas            #+#    #+#             */
/*   Updated: 2020/12/14 16:34:25 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	gest_error_arg(int ac, char **av)
{
	int fd;

	if (ac != 2 || !av[1])
	{
		ft_printf("Error\nInvalid argument\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		ft_printf("Error\nInvalid file\n");
		close(fd);
		return (0);
	}
	return (fd);
}

static void	set_pov(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = (int)((cub3d->player.fposy + (BLOCK_SIZE / 2)) / BLOCK_SIZE);
	x = (int)((cub3d->player.fposx - (BLOCK_SIZE / 2)) / BLOCK_SIZE);
	ft_printf("player at: %d, %d, %c\n", y, x, cub3d->config.map_ok[y][x]);
	if (cub3d->config.map_ok[y][x] == 'E')
		cub3d->config.pov = 2 * M_PI;
	else if (cub3d->config.map_ok[y][x] == 'N')
		cub3d->config.pov = M_PI / 2;
	else if (cub3d->config.map_ok[y][x] == 'W')
		cub3d->config.pov = M_PI;
	else
		cub3d->config.pov = 3 * M_PI_2;
}

int			main(int ac, char **av)
{
	t_cub3d		cub3d;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	line = NULL;
	if (!(fd = gest_error_arg(ac, av)))
		return (-1);
	ft_init_config(&cub3d.config);
	while (i > 0)
		i = ft_read_line(fd, line, &cub3d);
	close(fd);
	if (i == -1)
		return (-1);
	if (!(cub3d.config.map_ok = ft_parse_map(&cub3d)))
		return (-1);
	set_pov(&cub3d);
	if (window(cub3d))
		return (-1);
	return (0);
}
