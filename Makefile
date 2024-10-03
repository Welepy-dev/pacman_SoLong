# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 12:05:53 by marcsilv          #+#    #+#              #
#    Updated: 2024/10/03 12:05:56 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx_linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
SRC_DIR = srcs
UTILS_DIR = $(SRC_DIR)/utils
INC_DIR = includes
OBJ_DIR = .
HEADER = so_long.h

SRC_FILES =		./sources/init.c ./sources/movement.c ./sources/parser.c ./sources/render_map.c ./sources/so_long.c ./sources/validation.c \
				./sources/utils/utils.c ./sources/utils/utils_2.c
                
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

LIBFT = ./sources/libft/Makefile

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT))
	$(CC) $(OBJ_PATHS) -L./sources/libft -lft $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_linux -I ./sources/libft/includes -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I mlx_linux -I ./sources/libft/includes -c $< -o $@

clean:
	rm -f $(OBJ_PATHS)
	$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

.PHONY: all clean fclean re
