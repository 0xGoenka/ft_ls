# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 11:26:01 by eleclet           #+#    #+#              #
#    Updated: 2016/02/24 13:23:26 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CFLAGS = -Werror -Wextra -Wall
CC = gcc
SRC = src/format.c src/somefunction.c src/sys_utils.c src/shellparser.c src/list.c\
src/finc.c src/tfile.c src/recursive.c
OBJ = format.o somefunction.o sys_utils.o shellparser.o list.o tfile.o recursive.o\


all : $(NAME)

$(NAME) :
	@make re -C src/libft/
	@gcc  $(SRC) $(CFLAGS) -I./src/ libft/libft.a -o ft_ls
clean :
	@make clean -C src/libft/
fclean : clean
	rm $(NAME)
re : fclean all

debug :
	@make re -C src/libft/
	@gcc  $(SRC) $(CFLAGS) -g -I./src/ libft/libft.a -o ft_ls
