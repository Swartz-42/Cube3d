/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:26:29 by aducas            #+#    #+#             */
/*   Updated: 2020/03/05 19:05:38 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//recuperais la map et les options avec les verifs

int g_global = 0;

int		gest_error_arg(int ac, char **av, int fd)
{
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

void	resolution(char *line, t_reglage *reglage)
{
	int i;

	i = 0;
	reglage->resx = ft_atoi(line + 1);
	i = ft_strlen(line);
	while (!ft_isdigit(line[i]))
		i--;
	while (ft_isdigit(line[i]))
		i--;
	reglage->resy = ft_atoi(line + i);
}

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

void	lazy_parsing(char *str, int *i)
{
	while (str[*i] && str[*i] != ' ')
		*i = *i + 1;
	while (str[*i] && str[*i] == ' ')
		*i = *i + 1;
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
		reglage->map = ft_strjoin(reglage->map, ft_strjoin(line, "\n"));
	else if ((line[0] != '1' || line[ft_strlen(line) - 1] != '1') &&
			(read(fd, line, 0) >= 1))
	{
		ft_printf("ERROR\nerreur map\n");
		return (-1);
	}
	line = 0;
	if (ret == 0)
		return (0);
	return (1);
}

int		verif_map(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		i++;
	}
	return (1);
}

void	ft_init_map(t_reglage *reglage)
{
	reglage->textno = ft_strdup("");
	reglage->textso = ft_strdup("");
	reglage->textwe = ft_strdup("");
	reglage->textea = ft_strdup("");
	reglage->sprite = ft_strdup("");
	reglage->map = ft_strdup("");
	reglage->resx = 0;
	reglage->resy = 0;
	reglage->solr = 0;
	reglage->solg = 0;
	reglage->solb = 0;
	reglage->cielr = 0;
	reglage->cielg = 0;
	reglage->cielb = 0;
}

int		main(int ac, char **av)
{
	t_reglage	reglage;
	char		*line;
	int			fd;
	int			i;

	i = 1;
	fd = 1;
	line = NULL;
	ft_init_map(&reglage);
	if (!(fd = gest_error_arg(ac, av, fd)))
		return (-1);
	while (i > 0)
		i = ft_read_line(fd, line, &reglage);
	close(fd);
	ft_printf("%s", reglage.map);
	ft_printf("x: %d y: %d", reglage.resx, reglage.resy);
	return (0);
}
