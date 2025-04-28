MAKEFLAGS	= --no-print-directory

NAME		= philo

SRC_DIR		= ./src

SRC			= $(shell find $(SRC_DIR) -name "*.c")

BUILD_DIR	= ./build

HEADER		= ./includes/philo.h

INCLUDES	= ./includes

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

CC			= cc

FLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=thread

all: build $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -I$(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -I$(INCLUDES) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

build:
	@mkdir -p $(BUILD_DIR)

.PHONY: all clean fclean re build
