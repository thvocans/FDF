# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2017/09/26 13:07:47 by thvocans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re libmlx.a libclean libfclean mlxclean libft.a libmlx.a relib

NAME = exe

FLAGS = -Wall -Wextra -Werror
#FLAGS = -Wall -Wextra -Werror -lmlx -L./sierra -framework OpenGL -framework Appkit
#FLAGS = -Wall -Wextra -Werror

C_FOLDER = ./

H_FOLDER = ./

LIB_FOLD = ./libft

#GLIB_FOLD = ./sierra
GLIB_FOLD = ./el_capitan

LIB = $(LIB_FOLD)/libft.a

GLIB = $(GLIB_FOLD)/libmlx.a

SRC = main keyboard error parsing printer quatern bresenham

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIB) $(O_FILE)
	@gcc $(FLAGS) $(LIB) $(GLIB) -framework OpenGL -framework Appkit -o $@ $(O_FILE)
	@echo "\033[32mexecutable OK\033[0m"

./%.o: ./%.c
	@gcc -c $< $(FLAGS) -I$(LIB_FOLD) -o $@
	@echo "\033[32m$@\033[0m"

libft.a: $(LIB)

$(LIB):
	@$(MAKE) -C libft

libmlx.a:
	@$(MAKE) -C el_capitan

libclean:
	@$(MAKE) -C libft clean

mlxclean:
	@$(MAKE) -C el_capitan clean

clean: libclean
	@/bin/rm -f $(O_FILE)
	@echo "\033[32mrm .o files\033[0m"

libfclean:
	@$(MAKE) -C libft fclean

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "\033[32mrm $(NAME)\033[0m"

relib: libfclean libft.a

re: fclean all
