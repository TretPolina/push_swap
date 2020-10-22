# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fford <fford@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 16:08:43 by fford             #+#    #+#              #
#    Updated: 2020/03/06 21:12:47 by fford            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

.PHONY: all clean fclean re

SRC =	ft_printf.c specificator.c flags.c spec_x_check.c sub_func.c fourth_flag.c\
		spec_c_s.c spec_d_i.c spec_u.c spec_o.c spec_percent.c spec_x.c spec_p.c spec_f.c\
		ft_putchar_b.c ft_strlen_pf.c ft_strdup_pf.c ft_putstr_b.c\
		star.c spec_b.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

HEAD = includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEAD)
	gcc $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -rf $(NAME)

re: fclean all
