#include "../includes/cub3d.h"

//recuperais la map et les options

int	gest_error_arg(int ac, char **av, int fd)
{
	if(ac != 2 || !av[1])
	{
		ft_printf("ERROR\nErreur dans l'argument\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if(fd < 0 || !ft_strnstr(av[1], ".cub", ft_strlen(av[1])))
	{
		ft_printf("ERROR\nErreur mauvais fichier\n");
		return (0);
	}
	return (fd);
}

void resolution(char *line, cub_tab *reglage)
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

void	ft_rgb(char *line, cub_tab *reglage)
{
	int	i;

	i = 0;
	if(line[i] == 'C')
	{
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
	else
	{
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
}

void ft_parce(char *line, cub_tab *reglage)
{
	if(line[0] == 'R')
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
		reglage->textsprite = ft_strdup(line + 2);
	else if (line[0] == 'F' || line[0] == 'C')
		ft_rgb(line, reglage);
	else
		ft_printf("ERROR\nErreur dans un parametre\n");
}

int		ft_read_line(int fd, char *line, cub_tab *reglage)
{
	int ret;

	ret = get_next_line(fd, &line);
	if (ft_comp(line[0], "RNSWEFC"))
		ft_parce(line, reglage);
	else if (line[0] == '1' && line[ft_strlen(line) - 1] == '1')
	{
		line[ft_strlen(line)] = '\n';
		reglage->map = ft_strjoin(reglage->map, line);
	}
	else if (line[0] != '1' && line[ft_strlen(line) - 1] != '1' && (read(fd, line, 0) > 1))
	{
		ft_printf("ERROR\nerreur map\n");
		return (-1);
	}
	free(line);
	if (ret == 0)
		return (0);
	return (1);
}

int	verif_map(char *map)
{
	char *tmp;
	int i;
	int len;
	int len_tmp;

	i = 0;
	len = 0;
	len_tmp = 0;
	while (map[i] != '\0' && len == len_tmp)
	{
		len_tmp = len;
		while (map[i] != '\n')
			i++;
		if (!(tmp = malloc(sizeof(char) * i + 1)))
			return(-1);
		while (i >= 0)
		{
			tmp[i] = map[i];
			i--;
		}
		len = ft_strlen(tmp);
		free(tmp);
		tmp = 0;
	}
}

int main(int ac, char **av)
{
	cub_tab     *reglage;
	char        *line;
	int         fd;
	int			i;

	i = 1;
	fd = 1;
	reglage->map = 0;
	if (!(fd = gest_error_arg(ac, av, fd)))
		return (-1);
	while(i > 0)
		i = ft_read_line(fd, line, reglage);
	close(fd);
	verif_map(reglage->map);
	ft_printf("%s", reglage->map);
	ft_printf("x: %d y: %d", reglage->resx, reglage->resy);
	return (0);
}