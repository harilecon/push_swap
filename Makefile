# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsitoand <tsitoand@tsitoand@student.42a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 07:20:51 by tsitoand          #+#    #+#              #
#    Updated: 2026/03/23 13:32:17 by tsitoand         ###   ########.fr        #
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
		printf_stack.c\
		radix.c\
		range.c\
		main.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)
