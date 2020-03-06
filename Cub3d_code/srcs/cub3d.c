/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:26:29 by aducas            #+#    #+#             */
/*   Updated: 2020/03/06 14:17:25 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//recuperais la map et les options avec les verifs
// TODO Verif map

int		gest_error_arg(int ac, char **av)
{
	int fd;

	if (ac != 2 || !av[1])
	{
		ft_printf("ERROR\nErreur dans l'argument\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		ft_printf("ERROR\nErreur mauvais fichier\n");
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
	perso.vitx = 0;
	perso.vity = 0;
	if (key == W)
		perso.vitx = 1;
	else if (key == S)
		perso.vitx = -1;
	if (key == A)
		perso.vity = -1;
	else if (key == D)
		perso.vity = 1;
	ft_printf("vitx: %d vity: %d\n", perso.vitx, perso.vity);
}

void	ft_release_mouv(int key, t_perso perso)
{
	if (key == W)
		perso.vitx = 0;
	if (key == A)
		perso.vity = 0;
	if (key == S)
		perso.vitx = 0;
	if (key == D)
		perso.vity = 0;
	ft_printf("vitx: %d vity: %d\n", perso.vitx, perso.vity);
}

int		ft_parse_key(int key, t_jeu *jeu)
{
	if (key == ESC)
		ft_exit(jeu->win);
	else if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_mouv(key, jeu->perso);
	return (0);
}

int		ft_release_key(int key, t_jeu *jeu)
{
	if ((key == W) || (key == A) || (key == S) || (key == D))
		ft_release_mouv(key, jeu->perso);
	return (0);
}

int		window(t_jeu jeu)
{
	if (!(jeu.win.mlx_ptr = mlx_init()))
	{
		ft_printf("ERROR\nErreur lors de l'initialisation de minilibx\n");
		return (1);
	}
	jeu.win.title = ft_strdup("Cub3d.exe");
	jeu.win.win_ptr = mlx_new_window(jeu.win.mlx_ptr,
					jeu.reglage.x, jeu.reglage.y, jeu.win.title);
	if (jeu.win.win_ptr == NULL)
	{
		ft_printf("ERROR\nErreur creation fenetre de jeu\n");
		return (1);
	}
	mlx_hook(jeu.win.win_ptr, KeyPress, KeyPressMask, ft_parse_key, &jeu);
	mlx_hook(jeu.win.win_ptr, KeyRelease, KeyReleaseMask, ft_release_key,
				&jeu);
	mlx_loop(jeu.win.mlx_ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_jeu		jeu;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	line = NULL;
	ft_init_reglage(&jeu.reglage);
	if (!(fd = gest_error_arg(ac, av)))
		return (-1);
	while (i > 0)
		i = ft_read_line(fd, line, &jeu.reglage);
	close(fd);
	if (window(jeu))
		return (-1);
	return (0);
}
