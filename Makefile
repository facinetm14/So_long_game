# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 23:04:11 by fakouyat          #+#    #+#              #
#    Updated: 2022/08/09 00:59:18 by fakouyat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBS = ./libs/

MLX = ./mlx/libmlx.a

FT_PRINTF = $(LIBS)ft_printf/libftprintf.a

GNL = $(LIBS)gnl/gnl.a


SRCS = ./srcs/check_double_key.c\
	./srcs/checker_map.c\
	./srcs/close_windows.c\
	./srcs/display_map.c\
	./srcs/game_star.c\
	./srcs/key_mapping.c\
	./srcs/map.c\
	./srcs/moves.c\
	./srcs/players.c

OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : 
	make -C ./mlx/
	make -C $(LIBS)ft_printf/
	make -C $(LIBS)gnl/
	$(CC) $(CFLAGS) main.c $(SRCS) $(MLX) $(FT_PRINTF) $(GNL) -framework OpenGl -framework AppKit -o $(NAME)

clean :
	make clean -C ./mlx
	make clean -C $(LIBS)gnl
	make clean -C $(LIBS)ft_printf
	rm -rf $(OBJ)
	
fclean : clean
	make fclean -C $(LIBS)gnl
	make fclean -C $(LIBS)ft_printf
	rm -rf $(MLX)
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re