#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atilegen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/17 23:17:09 by atilegen          #+#    #+#              #
#    Updated: 2018/04/25 16:02:37 by atilegen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fdf

SRC = main.c hooks.c draw.c reader.c exit.c

.PHONY: re clean fclean all fillit libft
OBJ = $(SRC:.c=.o)
LIBFTFLAGS = -L./libft -lft
LIBFT = libft 

all: $(NAME)

%.o.c:
	@$(CC) -c $(subst .o,.c, $@) -I./libft $(CFLAGS) -o $@ 

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(OBJ) -I./libft $(LIBFTFLAGS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all