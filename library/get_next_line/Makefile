# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 14:15:09 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/13 19:23:40 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	printf "\033[32m.\033[0m"
	$(AR) $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
