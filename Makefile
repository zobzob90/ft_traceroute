NAME		= ft_traceroute

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I inc/

SRCS		= main.c \
		  src/init.c \
		  src/parsing.c \
		  src/socket.c \
		  src/traceroute.c \
		  src/utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ $(NAME) compiled!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "🧹 Objects cleaned!"

fclean: clean
	rm -f $(NAME)
	@echo "🧹 $(NAME) removed!"

re: fclean all

.PHONY: all clean fclean re
