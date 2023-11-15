# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 10:10:19 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/14 10:46:26 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT = ../libft/libft.a
SRCS = ft_is.c ft_print_flag.c ft_printf.c ft_putnbr_base.c ft_putptr.c


OBJS = $(SRCS:.c=.o)

.SILENT:

all:	$(LIBFT) $(NAME)

%.o:	%.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	printf "\033[32m.\033[0m"
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	make -sC libft

clean:
	rm -rf $(OBJS)
	make clean -sC ../libft

fclean: clean
	rm -rf $(NAME)
	make -s fclean -C ../libft

re: fclean all

.PHONY: all clean fclean re
