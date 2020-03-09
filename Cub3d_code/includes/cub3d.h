/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:24:24 by aducas            #+#    #+#             */
/*   Updated: 2020/03/09 12:44:52 by lrobert          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/include/libft.h"
# include "../../libft/include/get_next_line.h"
# include "../../libft/include/ft_printf.h"
# include "../../minilibx/mlx.h"
# include "../../minilibx/X.h"

# define ESC 	53
# define A		0
# define S		1
# define D		2
# define W		13
# define MAJ	257

typedef	struct	s_config
{
	int		x;
	int		y;
	char	*textno;
	char	*textso;
	char	*textwe;
	char	*textea;
	char	*sprite;
	int		r_floor;
	int		g_floor;
	int		b_floor;
	int		r_ceiling;
	int		g_ceiling;
	int		b_ceiling;
	char	*map;

}				t_config;

typedef	struct	s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*title;

}				t_window;

typedef struct	s_perso
{
	int	vitx;
	int	vity;
}				t_perso;

typedef	struct	s_cub3d
{
	t_config	config;
	t_window	win;
	t_perso		perso;
}				t_cub3d;

void			ft_rgb_ceiling(t_config *config, char *line);
void			ft_rgb_floor(t_config *config, char *line);
void			ft_rgb(char *line, t_config *config);

void			ft_init_config(t_config *config);
void			resolution(char *line, t_config *config);
int				ft_read_line(int fd, char *line, t_config *config);
void			ft_parse3d(char *line, t_config *config);

#endif
