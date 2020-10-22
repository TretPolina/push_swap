# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fford <fford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/31 17:54:09 by fford             #+#    #+#              #
#    Updated: 2020/09/14 12:41:10 by fford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap
NAME = libpushswap.a

LIB_DIR = ./ft_printf/
LIBFT = $(LIB_DIR)libftprintf.a

SRC_C = checker.c commands_1.c commands_2.c commands_3.c \
        create_stacks.c sub_functions.c flags.c

SRC_P = push_swap.c flags.c max_sort_seq.c fill_sort.c \
        commands_1.c commands_2.c commands_3.c count_cm.c count_cm_2.c \
        create_stacks.c sub_functions.c move_to_b.c

OBJ_C = $(SRC_C:.c=.o)
OBJ_P = $(SRC_P:.c=.o)

INCLUDE = ./includes/push_swap.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME_C) $(NAME_P) $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) -c $(FLAGS) $<

$(NAME_C): $(OBJ_C)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(FLAGS) -o $(NAME_C) $(OBJ_C) $(LIBFT)

$(NAME_P): $(OBJ_P)
	$(CC) $(FLAGS) -o $(NAME_P) $(OBJ_P) $(LIBFT)

$(NAME): $(OBJ_C) $(OBJ_P)
	cp ft_printf/libftprintf.a ./$(NAME)
	ar rc $(NAME) $(OBJ_C)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_C) $(OBJ_P)
	$(MAKE) -C $(LIB_DIR) clean
	@rm -rf push_swap.dSYM
	@rm -rf checker.dSYM

fclean: clean
	rm -rf $(NAME_C) $(NAME_P) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
	$(MAKE) fclean
	$(MAKE) all
