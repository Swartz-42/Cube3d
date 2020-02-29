#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../../libft/include/libft.h"

typedef	struct	jeu_tab
{
    int 	resx;
	int		resy;
    char	*textno;
	char	*textso;
	char	*textwe;
	char	*textea;
	char	*textsprite;
	int		solr;
	int		solg;
	int		solb;
	int		cielr;
	int		cielg;
	int		cielb;
	char	*map;

}				cub_tab;

typedef struct	m_tab
{
	char			*mapx;
	struct m_tab	*next;
}				map_tab;

#endif