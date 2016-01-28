# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 11:26:01 by eleclet           #+#    #+#              #
#    Updated: 2016/01/28 19:02:41 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Werror -Wextra -Wall
CC = gcc
SRC = src/format.c src/somefunction.c src/sys_utils.c src/getparam.c src/list.c
OBJ = format.o somefunction.o sys_utils.o getparam.o list.o

all : $(NAME)

$(NAME) :
	@make re -C src/libft/
	@gcc  $(SRC) $(CFLAGS) -I./src/ -o ft_ls
clean :
	@make clean -C src/libft/
fclean : clean
	rm $(NAME)
re : fclean all
