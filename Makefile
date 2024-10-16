NAME	=	cub3D

FILES	=	main.c \
			parse/map_parse.c \
			error_free.c \
			map_coordinates/coordinate_wrapper_filler.c \
			map_coordinates/floor_ceiling_wrapper_filler.c \
			map_coordinates/map_and_coordinates.c  \
			find_map/find_and_fill_map.c \
			map_coordinates/coordinate_validation.c \
			parse/validate_map.c \
			init.c \
			#ray_casting.c


LIBFT	=	libft/libft.a

#---------------------------------MLX---------------------------------------------#
LIBMLX	=	./MLX42
HEADERS	= -I ./includes -I $(LIBMLX)/include/MLX42/
INCLUDES	= -I include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

FtoO	=	$(FILES:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Ofast -g #-fsanitize=address
RM		=	rm -f

all:	$(LIBFT) libmlx $(NAME)

$(NAME): cub3d.h $(FtoO) 
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

.PHONY: all, libmlx, clean, fclean, re, 