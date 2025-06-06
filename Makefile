NAME	= so_long

SRCS	= so_long.c \
		so_long_utils.c \
		so_long_utils2.c \
		map.c \
		checkway.c \
		checkmove.c \
		moveset.c

GNL_DIR	= get_next_line
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJS	= $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

get_next_line/%.o: get_next_line/%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(SRCS:.c=.o) $(GNL_SRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re