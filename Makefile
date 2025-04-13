SRC		= So_long/get_next_line.c So_long/get_next_line_utils.c \
		  So_long/libft.c So_long/libft2.c \
		  So_long/main.c So_long/fill.c \
		  So_long/init.c So_long/free.c \
		  So_long/checks.c So_long/init_utils.c \
		  So_long/flood_fill.c So_long/moves.c \
		  So_long/error_msg.c
OBJ		= ${SRC:.c=.o}
MLX		= ./minilibx-linux/libmlx.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
LFLAGS	= -lX11 -lXext
RM = rm -rf

NAME = so_long
all: ${NAME}
${MLX}:
	${MAKE} -C ./minilibx-linux
${NAME}: ${OBJ} ${MLX}
	${CC} ${CFLAGS} ${OBJ} ${MLX} ${LFLAGS} -o ${NAME}
clean:
	${MAKE} clean -C ./minilibx-linux
	${RM} ${OBJ}
fclean: clean
	${MAKE} clean -C ./minilibx-linux
	${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re
.SECONDARY:
