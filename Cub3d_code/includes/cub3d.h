/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:24:24 by aducas            #+#    #+#             */
/*   Updated: 2020/03/06 13:51:53 by aducas           ###   ########lyon.fr   */
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

typedef	struct	s_reglage
{
	int		x;
	int		y;
	char	*textno;
	char	*textso;
	char	*textwe;
	char	*textea;
	char	*sprite;
	int		solr;
	int		solg;
	int		solb;
	int		cielr;
	int		cielg;
	int		cielb;
	char	*map;

}				t_reglage;

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

typedef	struct	s_jeu
{
	t_reglage	reglage;
	t_window	win;
	t_perso		perso;
}				t_jeu;

void			ft_rgb_roof(t_reglage *reglage, char *line);
void			ft_rgb_floor(t_reglage *reglage, char *line);
void			ft_rgb(char *line, t_reglage *reglage);

void			ft_init_reglage(t_reglage *reglage);
void			resolution(char *line, t_reglage *reglage);
int				ft_read_line(int fd, char *line, t_reglage *reglage);
void			ft_parce(char *line, t_reglage *reglage);

#endif
