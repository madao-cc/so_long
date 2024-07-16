# Standard
NAME	=	so_long

# Directories
MINILIBX	=	-I/usr/include -Imlx

# Compiller and CFlags
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
RM		=	rm -f

# Includes
LIBFT		= libft/libft.a

# Source files
SRCS	=	so_long.c		\
		picture_handler.c	\
		moves_handler.c		\
		map_handler.c		\
		map_checker.c		\
		errors_handler.c	\

# Object files
OBJS	=	$(SRCS:.c=.o)

#Build rules

start:
	@make all

$(LIBFT):
	@make -C ./libft

all:	$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(MINILIBX)

clean:
	rm -rf $(OBJS)
	@make clean -C ./libft

fclean:		clean
	rm -rf $(NAME)
	@$(RM) $(LIBFT)

re:	fclean all

.PHONY:		start all clean fclean re 