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

NAME        =   libftprintf.a

FLAGS       =    -Wall -Wextra -Werror  

HEADER      =   includes/ft_printf.h

SRC         =   srcs/ft_display_addr.c		\
				srcs/ft_display_char.c		\
				srcs/ft_display_hex.c		\
				srcs/ft_display_int.c		\
				srcs/ft_display_percent.c	\
				srcs/ft_display_str.c		\
				srcs/ft_display_u_int.c		\
				srcs/ft_display.c			\
				srcs/ft_init.c				\
				srcs/ft_parse.c				\
				srcs/ft_precision.c			\
				srcs/ft_printf.c			\
				srcs/ft_wildcard.c			

OBJ			=	${SRC:.c=.o}

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

