.PHONY: all clean fclean re

# Name of file
NAME		=	Cub3D

# Name directory
PATH_INC	=	Cub3d_code/includes
PATH_SRC	=	Cub3d_code/srcs
PATH_OBJ	=	Cub3d_code/objs
PATH_LIBFT	=	libft
PATH_LIBMLX	=	minilibx

# List of sources
SRCS		=	window.c ft_config.c ft_rgb.c Keys_manag.c\
				where_is_waldo.c check_map.c raycast.c display.c\
				move.c minimap.c scan.c
OBJS		=	$(addprefix $(PATH_OBJ)/, $(SRCS:.c=.o))
INCS		=	$(addprefix $(PATH_INC)/, cub3d.h)

# Commands of compilation
COMP		=	clang
COMP_FLAG	=	-Wall -Werror #-Wextra
COMP_ADD	=	-I$(PATH_INC) -I$(PATH_LIBMLX)

# Others Command
RM			=	/bin/rm

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ echo "$(_INFO) Initialize $(NAME)"
	@ $(shell mkdir -p $(PATH_OBJ))
	@ make -C $(PATH_LIBFT)
	@ make -C $(PATH_LIBMLX)

$(NAME): $(OBJS) $(INCS)
	@ $(COMP) $(COMP_FLAG) -O2 -o $(NAME) $(COMP_ADD) $(PATH_SRC)/cub3d.c $(PATH_LIBFT)/libft.a $(PATH_LIBMLX)/libmlx.a -framework OpenGL -framework AppKit $(OBJS)

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.c $(INCS)
	@ $(COMP) $(COMP_FLAG) $(COMP_ADD) -c $< -o $@
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ make -C $(PATH_LIBFT) clean
	@ make -C $(PATH_LIBMLX) clean
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)
	@ make -C $(PATH_LIBFT) fclean

re: fclean all
