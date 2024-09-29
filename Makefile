# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/14 14:34:40 by marcsilv          #+#    #+#              #
#    Updated: 2024/09/29 18:47:31 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC_DIR = sources
SRCS = 	./sources/init.c \
	./sources/utils.c \
	./sources/parser.c \
	./sources/so_long.h \
	./sources/so_long.c  \
	./sources/movement.c  \
	./sources/render_map.c \
	./sources/validation.c  \

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

make_libft:
	make -C ./sources/libft
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)