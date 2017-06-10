# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2017/06/10 16:03:50 by thvocans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re

NAME = exe

FLAGS = #-Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror

C_FOLDER = ./

H_FOLDER = ./

LIB_FOLD = ./libft/

LIB = libft.a

SRC = main ft_read ft_tab\
	  ft_check_char ft_check_format ft_check_shape\
	  ft_split_pieces ft_save_shape ft_struct_fill\
	  ft_square_size placement ft_valid_loc

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIB) $(O_FILE)
	@gcc $(FLAGS) -L$(LIB_FOLD) -I$(LIB_FOLD) -lft -o $@ $(O_FILE)
	@echo "\033[32mexecutable OK\033[0m"

./%.o: ./%.c
	@gcc -c $(FLAGS) $< -I$(LIB_FOLD) -o $@
	@echo "\033[32m$@\033[0m"

$(LIB):
	@$(MAKE) -C libft

libclean:
	@$(MAKE) -C libft clean

clean: libclean
	@/bin/rm -f $(O_FILE)
	@echo "\033[32mrm .o files\033[0m"

libfclean:
	@$(MAKE) -C libft fclean

fclean: clean libfclean
	@/bin/rm -f $(NAME)
	@echo "\033[32mrm $(NAME)\033[0m"

re: fclean all
