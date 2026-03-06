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
TOTAL		= $(words $(SRCS))

# Colors
RED		= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN		= \033[1;36m
RESET		= \033[0m

all: header $(NAME)

header:
	@echo "$(CYAN)"
	@echo "  _____ _     _____                                         _       "
	@echo " |  ___| |_  |_   _| __ __ _  ___ ___ _ __ ___  _   _| |_ ___  "
	@echo " | |_  | __|   | || '__/ _\` |/ __/ _ \\ '__/ _ \\| | | | __/ _ \\ "
	@echo " |  _| | |_    | || | | (_| | (_|  __/ | | (_) | |_| | ||  __/ "
	@echo " |_|    \\__|   |_||_|  \\__,_|\\___\\___|_|  \\___/ \\__,_|\\__\\___| "
	@echo "$(RESET)"

$(NAME): $(OBJS)
	@printf "$(BLUE)🔗 Linking...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) compiled successfully!$(RESET)"

CURRENT = 0
$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL)))))
	$(eval FILLED := $(shell echo $$(($(CURRENT) * 20 / $(TOTAL)))))
	$(eval EMPTY := $(shell echo $$((20 - $(FILLED)))))
	@printf "$(YELLOW)⚙️  Compiling $(RESET)%-30s $(CYAN)[" "$<"
	@printf "$(GREEN)%0.s█$(RESET)" $(shell seq 1 $(FILLED)) 2>/dev/null || true
	@printf "$(RED)%0.s░$(RESET)" $(shell seq 1 $(EMPTY)) 2>/dev/null || true
	@printf "$(CYAN)] $(YELLOW)%3d%%$(RESET)\n" $(PERCENT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)🧹 Objects cleaned!$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧹 $(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re header
