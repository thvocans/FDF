# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thvocans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 19:03:58 by thvocans          #+#    #+#              #
#    Updated: 2017/05/11 16:30:03 by thvocans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all fclean clean re

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -I $(H_FOLDER)

C_FOLDER = ./

H_FOLDER = ./

SRC = ft_memset ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_bzero\
	  ft_strchr ft_strrchr ft_strlcat\
	  ft_strlen ft_strcmp ft_strncmp ft_strcat ft_strncat ft_strcpy ft_strncpy\
	  ft_strdup ft_strstr ft_strnstr\
	  ft_atoi\
	  ft_isalpha ft_isdigit ft_isascii ft_isalnum ft_isprint\
	  ft_toupper ft_tolower\
	  ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putstr ft_putstr_fd\
	  ft_putnbr ft_putnbr_fd ft_itoa\
	  ft_strequ ft_strnequ ft_strclr ft_strnew ft_strdel ft_striter ft_striteri\
	  ft_strsub ft_strjoin ft_strtrim ft_strmap ft_strmapi ft_strsplit\
	  ft_memalloc ft_memdel\
	  ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
	  ft_malloncat ft_isspace ft_list_last ft_sqrt ft_puttab

C_FILE = $(addsuffix .c,$(addprefix $(C_FOLDER),$(SRC)))

O_FILE = $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(O_FILE)
	@ar rc $@ $^
	@echo "\033[36mlibft.a OK\033[0m"
	@ranlib $(NAME)
	@echo "\033[36mranlib libft.a\033[0m"

./%.o: ./%.c
	@gcc -c $(FLAGS) $< -o $@
#	@echo -n \\033[32m$@\\033[0m	

clean:
	@/bin/rm -f $(O_FILE)
	@echo "\033[36mrm lib .o files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[36mrm $(NAME)\033[0m"

re: fclean all
