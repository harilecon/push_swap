# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 07:20:51 by tsitoand          #+#    #+#              #
#    Updated: 2026/03/25 08:40:14 by tsitoand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC =	buble.c\
		ft_printf_address.c\
		ft_printf.c\
		ft_printf_char.c\
		ft_printf_int_hexlow.c\
		ft_printf_int_hexup.c\
		ft_printf_int_nb.c\
		ft_printf_int_unsigned_nb.c\
		ft_printf_long_hexlow.c\
		ft_printf_string.c\
		insertion.c\
		move_01.c\
		move_02.c\
		move_03.c\
		move_04.c\
		radix.c\
		range.c\
		main.c\
		adaptative.c\
		bunch.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

libft :
	make -C libft all
	mv libft/libft.a .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft fclean
	rm -rf libft.a
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : libft re clean fclean
