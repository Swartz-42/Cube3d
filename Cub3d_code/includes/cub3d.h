/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:24:24 by aducas            #+#    #+#             */
/*   Updated: 2020/03/04 14:00:04 by aducas           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/include/libft.h"

typedef	struct	s_reglage
{
	int		resx;
	int		resy;
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

typedef struct	s__map_tab
{
	char			*mapx;
	struct m_tab	*next;
}				t_map_tab;

#endif
