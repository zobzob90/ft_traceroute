NAME		= ft_traceroute

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I inc/
OBJ_DIR		= obj/

SRCS		= main.c \
		  src/init.c \
		  src/parsing.c \
		  src/socket.c \
		  src/traceroute.c \
		  src/utils.c

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ $(NAME) compiled!"

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "🧹 Objects cleaned!"

fclean: clean
	rm -f $(NAME)
	@echo "🧹 $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
