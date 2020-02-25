# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrobert <lrobert@student.le-101.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 14:01:52 by lrobert           #+#    #+#              #
#    Updated: 2020/02/19 14:01:52 by lrobert          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY:	all clean fclean re

NAME		=	libft.a

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	include/libft.h

SRC			=		src/ft_atoi.c				\
					src/ft_bases.c				\
					src/ft_bzero.c				\
					src/ft_calloc.c				\
					src/ft_comp.c				\
					src/ft_cpy_line.c			\
					src/ft_isalnum.c			\
					src/ft_isalpha.c			\
					src/ft_isascii.c			\
					src/ft_isdigit.c			\
					src/ft_isprint.c			\
					src/ft_itoa.c				\
					src/ft_itoabase.c			\
					src/ft_memccpy.c			\
					src/ft_memchr.c				\
					src/ft_memcmp.c				\
					src/ft_memcpy.c				\
					src/ft_memmove.c			\
					src/ft_memset.c				\
					src/ft_putchar_fd.c			\
					src/ft_putendl_fd.c			\
					src/ft_putnbr_fd.c			\
					src/ft_putnbr_base.c		\
					src/ft_putnchar_fd.c		\
					src/ft_putnstr_fd.c			\
					src/ft_putstr_fd.c			\
					src/ft_split.c				\
					src/ft_strchr.c				\
					src/ft_strdup.c				\
					src/ft_strjoin.c			\
					src/ft_strlcat.c			\
					src/ft_strlcpy.c			\
					src/ft_strlen.c				\
					src/ft_strmapi.c			\
					src/ft_strncmp.c			\
					src/ft_strnstr.c			\
					src/ft_strrchr.c			\
					src/ft_strtrim.c			\
					src/ft_substr.c				\
					src/ft_tolower.c			\
					src/ft_toupper.c			\
					src/ft_lstadd_back.c		\
					src/ft_lstadd_front.c		\
					src/ft_lstclear.c			\
					src/ft_lstdelone.c			\
					src/ft_lstiter.c			\
					src/ft_lstlast.c			\
					src/ft_lstmap.c				\
					src/ft_lstnew.c				\
					src/ft_lstsize.c			\
					src/get_next_line.c			\
					src/ft_display_addr.c		\
					src/ft_display_char.c		\
					src/ft_display_hex.c		\
					src/ft_display_int.c		\
					src/ft_display_percent.c	\
					src/ft_display_str.c		\
					src/ft_display_u_int.c		\
					src/ft_display.c			\
					src/ft_init.c				\
					src/ft_parse.c				\
					src/ft_precision.c			\
					src/ft_printf.c			\
					src/ft_wildcard.c

OBJS			=	${SRC:.c=.o}

C-O			= gcc $(FLAGS)  -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
	@ ar rcs $(NAME) $(OBJS)
	
%.o: %.c $(HEADER)
	@ printf "\033[0;38;5;226mCompilation de \033[1m$< ..."
	@ $(C-O)
	@ printf "\r                                                                                                                                                    \r"

clean:
	@ rm -rf $(OBJS)

fclean:	clean
	@ rm -rf $(NAME)

re:	fclean all
