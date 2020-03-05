# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lrobert <lrobert@student.le-101.fr>        +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/02/10 13:42:37 by lrobert      #+#   ##    ##    #+#        #
#    Updated: 2020/02/10 13:42:37 by lrobert     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME        	=   Cub3d

FLAGS       	=    -Wall -Wextra -Werror  

HEADER      	=   Cub3d_code/includes/cub3d.h	\
					minilibx/mlx.h

PATH_INC			=	Cub3d_code/includes
PATH_INC_MINILIBX	=	minilibx

SRC         	=   Cub3d_code/srcs/cub3d.c

LIBFT_PATH		=	./libft
LIBFT			=	./libft/libft.a

MINI_LIBX_PATH	=	minilibx
MINI_LIBX		=	./minilibx/libmlx.a

OBJSRC = $(SRC:.c=.o)

all:	$(LIBFT) $(MINI_LIBX) $(NAME)

$(NAME):	$(LIBFT) $(MINI_LIBX) $(OBJSRC)
	@ gcc $(FLAGS) -o $(NAME) -I$(PATH_INC) -I$(PATH_INC_MINILIBX) $(MINI_LIBX) $(LIBFT) $(OBJSRC)

$(LIBFT):
	@ make -C $(LIBFT_PATH)

$(MINI_LIBX):
	@ make -C $(MINI_LIBX_PATH)

%.o: %.c $(HEADER)
	@ printf "\033[2K\033[0;38;5;226mCompilation de \033[1m$< ..."
	@ gcc $(OBJSRC) -i $(HEADER) -c $< -o $@


clean:
	@ make -C $(LIBFT_PATH) clean
	@ make -C $(MINI_LIBX_PATH) clean

fclean:	clean
	@ rm -rf *.out
	@ rm -rf $(NAME)
	@ make -C $(LIBFT_PATH) fclean

re:	fclean all

.PHONY: all clean fclean re