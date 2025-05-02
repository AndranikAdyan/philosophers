MAKEFLAGS	= --no-print-directory

NAME		= philo

SRC_DIR		= ./src
BUILD_DIR	= ./build
INCLUDES	= ./includes
HEADER		= $(INCLUDES)/philo.h

SRC			= $(shell find $(SRC_DIR) -name "*.c")
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

CC			= cc
FLAGS		= -Wall -Wextra -Werror

GREEN		= \033[38;2;124;227;139m
YELLOW		= \033[38;2;250;163;86m
RED			= \033[38;2;255;99;99m
BLUE		= \033[38;2;100;149;237m
RESET		= \033[0m

all: build $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c Makefile $(HEADER)
	@mkdir -p ./build
	@echo "🔧 $(BLUE)Compiling: $(YELLOW)$<$(RESET)"
	@$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ) -o $(NAME)
	@echo "✅ $(GREEN)Build complete: $(NAME)$(RESET)"

clean:
	@echo "🧹 $(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ)
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "🗑️  $(RED)Removing binary: $(NAME)$(RESET)"
	@rm -rf $(NAME)

re: fclean all

build:
	@mkdir -p $(BUILD_DIR)

.PHONY: all clean fclean re build
