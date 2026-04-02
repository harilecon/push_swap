# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsitoand <tsitoand@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 07:20:51 by tsitoand          #+#    #+#              #
#    Updated: 2026/04/02 18:14:01 by tsitoand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SRC = 	insertion_sort.c\
		move_01.c\
		move_02.c\
		move_03.c\
		struct_utils.c\
		radix_sort.c\
		chunck_sort.c\
		main.c\
		adaptative.c\
		benchmark.c\
		struct_argument.c\
		flag.c\
		utils_01.c\
		utils_02.c\
		ft_free.c\
		ft_printf_address_fd.c\
		ft_printf_char_fd.c\
		ft_printf_fd.c\
		ft_printf_int_hexlow_fd.c\
		ft_printf_int_hexup_fd.c\
		ft_printf_int_nb_fd.c\
		ft_printf_int_unsigned_nb_fd.c\
		ft_printf_long_hexlow_fd.c\
		print_double_fd.c\
		ft_printf_string_fd.c\
		double.c\
		min_max.c\
		check_null_space.c\
		few_elements.c\
		five_elements.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

libft/libft.a:
	make -C libft all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C libft clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft fclean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : libft re clean fclean
