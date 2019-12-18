# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbaker <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 13:38:16 by kbaker            #+#    #+#              #
#    Updated: 2019/12/17 20:24:59 by kbaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = -c
FLAGS = -Wall -Wextra -Werror
CONFIG = gcc -g $(HEADER) $(FLAGS) $(SRC)
CONFIG2 = ar rc $(NAME) $(OBJ) $(LIBFT)
CONFIG3 = ranlib $(NAME)
LIBFT = libft/*.o

SRC = ft_flags.c ft_itoa_base.c ft_uitoa_base.c ft_lengths.c ft_utilities.c ft_parsing.c ft_hash_prec_and_w.c \
	   ft_doings.c ft_fftoa.c ft_lengths.c ft_printf.c ft_convs.c ft_convs2.c ft_parsing_convs.c ft_prec_and_width.c\
	   ft_prec_and_width2.c  ft_double_perc.c ft_minus_hash.c ft_minus_string.c ft_searching_and_nbr_zero.c ft_hash_width_zero.c ft_convs_if_else.c ft_minus_prec_and_ifs.c ft_len_of_pw2.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(LIBFT) $(SRC)
	$(CONFIG)
	$(CONFIG2)
	$(CONFIG3)

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
