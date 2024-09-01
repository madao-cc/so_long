# Standard
NAME	=	so_long

# Directories
MLX_PATH	=	./minilibx-linux
MINILIBX	=	-I/usr/include -I$(MLX_PATH)
FT_PRINTF	=	./ft_printf/ft_printf.a

# Compiller and CFlags
CC		=	gcc -g
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-L$(MLX_PATH) -lmlx -L/usr/lib/X11 -lXext -lX11
RM		=	rm -f

# Source files
SRCS	=	check_map_file_pt2.c	\
		check_map_file.c	\
		handle_map.c	\
		initial_checks.c	\
		moves_counter_utils.c	\
		moves.c	\
		pictures.c	\
		so_long.c	\
		get_next_line.c	\
		get_next_line_utils.c	\
		libft_resources.c	\
		pictures_pt2.c	\

# Object files
OBJS	=	$(SRCS:.c=.o)

#Build rules

start:
	@make all

$(FT_PRINTF):
	@make -C ./ft_printf

all:	$(NAME)

$(NAME):	$(OBJS) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(MINILIBX)

clean:
	rm -rf $(OBJS)
	@make clean -C ./ft_printf

fclean:		clean
	rm -rf $(NAME)
	@$(RM) $(FT_PRINTF)

re:	fclean all

.PHONY:		start all clean fclean re 