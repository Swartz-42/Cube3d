/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:26:29 by aducas            #+#    #+#             */
/*   Updated: 2020/03/09 17:30:50 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#define PI 3.14159
#include <math.h>

//recuperais la map et les options avec les verifs
// TODO Verif map

int		gest_error_arg(int ac, char **av)
{
	int fd;

	if (ac != 2 || !av[1])
	{
		ft_printf("ERROR\nInvalid argument\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		ft_printf("ERROR\nInvalid file\n");
		close(fd);
		return (0);
	}
	return (fd);
}

void	ft_exit(t_window win)
{
	mlx_destroy_window(win.mlx_ptr, win.win_ptr);
	exit(0);
}

void	ft_mouv(int key, t_perso perso)
{
	if (key == W && perso.vitx != 1)
		perso.vitx = 1;
	else if (key == S && perso.vitx != -1)
		perso.vitx = -1;
	if (key == A && perso.vity != -1)
		perso.vity = -1;
	else if (key == D && perso.vity != 1)
		perso.vity = 1;
	ft_printf("vitx: %d vity: %d\n", perso.vitx, perso.vity);
}

void	ft_release_mouv(int key, t_perso perso)
{
	if (key == W || key == S)
		perso.vitx = 0;
	if (key == A || key == D)
		perso.vity = 0;
	ft_printf("vitx: %d vity: %d\n", perso.vitx, perso.vity);
}

int		ft_parse_key(int key, t_cub3d *cub3d)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	ft_printf("key: %d\n", key);
	if (key == ESC)
		ft_exit(cub3d->win);
	else if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_mouv(key, cub3d->perso);
	else if (key == MAJ)
	{
		cub3d->win.img = mlx_xpm_file_to_image (cub3d->win.mlx_ptr, cub3d->config.textno, &width, &height);
		mlx_put_image_to_window(cub3d->win.mlx_ptr, cub3d->win.win_ptr, cub3d->win.img, 0, 0);
	}
	else if (key == 12)
		mlx_destroy_image (cub3d->win.mlx_ptr, cub3d->win.img);
	return (0);
}

int		ft_release_key(int key, t_cub3d *cub3d)
{
	if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_release_mouv(key, cub3d->perso);
	return (0);
}

int		window(t_cub3d cub3d)
{
	if (!(cub3d.win.mlx_ptr = mlx_init()))
	{
		ft_printf("ERROR\nminilibx initialisation failed\n");
		return (1);
	}
	cub3d.win.title = ft_strdup("Cub3d.exe");
	cub3d.win.win_ptr = mlx_new_window(cub3d.win.mlx_ptr,
					cub3d.config.x, cub3d.config.y, cub3d.win.title);
	if (cub3d.win.win_ptr == NULL)
	{
		ft_printf("ERROR\nCould not create cub3d window\n");
		return (1);
	}
	mlx_hook(cub3d.win.win_ptr, KeyPress, KeyPressMask, ft_parse_key, &cub3d);
	mlx_hook(cub3d.win.win_ptr, KeyRelease, KeyReleaseMask, ft_release_key,
			&cub3d);
	mlx_loop(cub3d.win.mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_cub3d		cub3d;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	line = NULL;
	ft_init_config(&cub3d.config);
	if (!(fd = gest_error_arg(ac, av)))
		return (-1);
	while (i > 0)
		i = ft_read_line(fd, line, &cub3d.config);
	close(fd);
	if (window(cub3d))
		return (-1);
	return (0);
}
