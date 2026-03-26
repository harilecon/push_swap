# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 07:20:51 by tsitoand          #+#    #+#              #
#    Updated: 2026/03/26 12:37:49 by tsitoand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC =	bubble_sort.c\
		ft_printf_address.c\
		ft_printf.c\
		ft_printf_char.c\
		ft_printf_int_hexlow.c\
		ft_printf_int_hexup.c\
		ft_printf_int_nb.c\
		ft_printf_int_unsigned_nb.c\
		ft_printf_long_hexlow.c\
		ft_printf_string.c\
		insertion_sort.c\
		move_01.c\
		move_02.c\
		move_03.c\
		struct_utils.c\
		radix_sort.c\
		range_sort.c\
		main.c\
		adaptative.c\
		benchmark.c\
		struct_argument.c\
		choose_algo.c\
		utils_01.c\
		utils_02.c\
		ft_free.c\
		ft_printf_address_error.c\
		ft_printf_char_error.c\
		ft_printf_error.c\
		ft_printf_int_hexlow_error.c\
		ft_printf_int_hexup_error.c\
		ft_printf_int_nb_error.c\
		ft_printf_int_unsigned_nb_error.c\
		ft_printf_long_hexlow_error.c\
		print_double_error.c\
		ft_printf_string_error.c


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
