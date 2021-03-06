/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:08:03 by aducas            #+#    #+#             */
/*   Updated: 2020/12/14 16:27:13 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../../libft/include/libft.h"
# include "../../libft/include/get_next_line.h"
# include "../../libft/include/ft_printf.h"
# include "../minilibx/mlx.h"

# define ESC 			53
# define A				0
# define S				1
# define D				2
# define W				13
# define MAJ			257
# define FD				123
# define FG				124
# define FOV			60
# define BLOCK_SIZE		64

typedef	struct		s_config
{
	enum e_boolean	fsave;
	float			pov;
	float			deep;
	char			*textno;
	char			*textso;
	char			*textwe;
	char			*textea;
	char			*sprite;
	char			*map;
	char			**map_ok;
	int				x_max;
	int				y_max;
	int				rgb_floor;
	int				rgb_ceiling;
}					t_config;

typedef	struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	float			x;
	float			y;
}					t_window;

typedef struct		s_player
{
	float			fposx;
	float			fposy;
	float			vit;
	enum e_boolean	frontward;
	enum e_boolean	backward;
	enum e_boolean	rightward;
	enum e_boolean	leftward;
}					t_player;

typedef	struct		s_cub3d
{
	t_config		config;
	t_window		win;
	t_player		player;
}					t_cub3d;

/*
**check_map
*/
char				**ft_parse_map(t_cub3d *cub3d);

/*
**window
*/
int					window(t_cub3d cub3d);

/*
**config
*/
void				ft_init_config(t_config *config);
int					ft_read_line(int fd, char *line, t_cub3d *cub3d);

/*
**rgb
*/
int					rgb_int(unsigned char alpha, unsigned char r,
							unsigned char g, unsigned char b);
int					ft_rgb(char *line, t_config *config);

/*
**key control
*/
int					ft_exit(t_window *win);
int					ft_release(int key, t_cub3d *cub3d);
int					ft_parse_key(int key, t_cub3d *cub3d);

/*
**player
*/
int					find_player(char **map_ok, t_cub3d *cub3d);
void				ft_mouv(t_player *player, t_config *config);

/*
**display
*/
int					display_game(t_cub3d *cub3d);
void				display_wall(int x, float projected_wall, t_cub3d cub3d);
void				minimap(t_cub3d cub3d);

/*
**raycast
*/
float				rayon_h(t_cub3d cub3d, float alpha);
float				rayon_v(t_cub3d cub3d, float alpha);
void				scan(t_cub3d *cub3d);

#endif
