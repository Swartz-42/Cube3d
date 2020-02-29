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
# a changer pour que ca fasse un ./cub3d #

.PHONY: all clean fclean re

NAME        =   Cub3d.a

FLAGS       =    -Wall -Wextra -Werror  

HEADER      =   Cub3d_code/includes/cub3d.h

SRC         =   Cub3d_code/srcs/

OBJ			=	#${SRC:.c=.o}

LIBFT_PATH	=	libft
LIBFT		=	libft.a

C-O			=	gcc $(FLAGS) -c $< -o $@

all:	$(LIBFT) $(NAME)

$(LIBFT):
	@ make -C $(LIBFT_PATH)

$(NAME):	$(OBJ)
	@ ar rcs $(NAME) $(LIBFT_PATH)/src/*.o $(OBJ)


%.o: %.c $(HEADER)
	@ printf "\033[0;38;5;225mCompilation de \033[1m$< ..."8
	@ $(C-O)
	@ printf "\r                                                                                                                                                                          \r"

clean:
	@ rm -rf $(OBJ)
	@ make -C $(LIBFT_PATH) clean

fclean:	clean
	@ rm -rf *.out
	@ rm -rf $(NAME)
	@ make -C $(LIBFT_PATH) fclean 

re:	fclean all

