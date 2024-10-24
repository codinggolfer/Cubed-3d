NAME	=	cub3D

FILES	=	sources/main.c \
			sources/error_free.c \
			sources/parse/map_parse.c \
			sources/map_coordinates/coordinate_wrapper_filler.c \
			sources/map_coordinates/floor_ceiling_wrapper_filler.c \
			sources/map_coordinates/map_and_coordinates.c  \
			sources/find_map/find_and_fill_map.c \
			sources/map_coordinates/coordinate_validation.c \
			sources/parse/validate_map.c \
			sources/game/init.c \
			sources/game/init_utils.c \
			sources/game/ray_casting.c \
			sources/game/run.c \
			sources/game/move.c \
			sources/game/rotate.c \
			sources/game/rendering.c


LIBFT	=	libft/libft.a

#---------------------------------MLX---------------------------------------------#
LIBMLX	=	./MLX42
HEADERS	= -I ./includes -I $(LIBMLX)/include/MLX42/
INCLUDES	= -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FtoO	=	$(FILES:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Ofast 
RM		=	rm -f

all:	$(LIBFT) libmlx $(NAME)

$(NAME): ./includes/cub3d.h $(FtoO) 
	$(CC) $(CFLAGS) $(HEADERS) $(FtoO) $(INCLUDES) $(LIBS) $(LIBFT) -o $(NAME)

libmlx: 
	@if [ ! -d $(LIBMLX)/build ]; then\
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4;\
	fi

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@ && printf "Compiling: $(notdir $<) "

clean:
	@make fclean -C libft
	@rm -rf $(LIBMLX)/build
	$(RM) $(FtoO)

fclean: clean
	$(RM) $(NAME) $(FtoO) $(LIBFT) $(LIBMLX)/build

re: fclean all

.PHONY: all, libmlx, clean, fclean, re