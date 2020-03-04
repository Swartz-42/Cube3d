# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducas <aducas@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 11:01:57 by abourbou          #+#    #+#              #
#    Updated: 2020/03/04 14:58:32 by aducas           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


#VARIABLE

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

NAME		=	libft.a

SRC 		=	$(addprefix $(GNL_PATH)/,$(SRC_GNL)) \
				$(addprefix $(LIBFT_PATH)/,$(SRC_LIBFT)) \
				$(addprefix $(PRINTF_PATH)/,$(SRC_PRINTF))

LIBFT_PATH	=	lib_common
SRC_LIBFT	= 	ft_atoi.c  ft_strdup.c ft_bzero.c \
				ft_strjoin.c ft_calloc.c ft_strlcat.c ft_isalnum.c \
	 			ft_memccpy.c ft_strlcpy.c ft_isalpha.c ft_memchr.c \
   				ft_strlen.c ft_isascii.c ft_memcmp.c ft_strmapi.c \
				ft_isdigit.c ft_memcpy.c ft_strncmp.c ft_isprint.c \
	 			ft_memmove.c ft_strnstr.c ft_itoa.c ft_memset.c \
				ft_strrchr.c  ft_putchar_fd.c ft_strtrim.c  ft_putendl_fd.c \
				ft_substr.c  ft_putnbr_fd.c ft_tolower.c  ft_putstr_fd.c \
				ft_toupper.c  ft_split.c ft_strchr.c  ft_strcmp.c \
				ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
				ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c \
				ft_lstlast_bonus.c ft_lst_addnew.c \
				is_in.c ft_usefull_free.c wrm.c


GNL_PATH	=	get_next_line
SRC_GNL		=	get_next_line.c			\
				get_next_line_utils.c	\

PRINTF_PATH	=	ft_printf
SRC_PRINTF	=	ft_display_addr.c		\
				ft_display_char.c		\
				ft_display_hex.c		\
				ft_display_int.c		\
				ft_display_percent.c	\
				ft_display_str.c		\
				ft_display_u_int.c		\
				ft_display.c			\
				ft_init.c				\
				ft_parse.c				\
				ft_precision.c			\
				ft_printf.c				\
				ft_wildcard.c			\

RM 			= 	rm -f

INCL 		=	libft.h get_next_line.h ft_printf.h

INCLUDE		=	$(addprefix include/,$(INCL))

OBJ			= 	$(SRC:.c=.o)

#RULES

all 		:	$(OBJ) $(NAME)

$(NAME) 	:	$(OBJ) $(INCLUDE)
				ar r $(NAME) $(OBJ)
				ranlib $(NAME)

%.o 		:	%.c $(INCLUDE)
				$(CC) -c -o $@ $< $(CFLAGS)

clean 		:
				@$(RM) $(OBJ)

fclean 		: 	clean
				@$(RM) $(NAME)

re 			: 	fclean all

norm 		:	$(SRC)
				norminette $(SRC)  $(INCLUDE)

.PHONY 		:	 clean fclean
