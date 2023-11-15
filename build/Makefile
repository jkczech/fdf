# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 12:07:05 by jkoupy            #+#    #+#              #
#    Updated: 2023/11/14 10:55:12 by jkoupy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END = \033[0m
RED = \033[31m
GREEN = \033[32m

NAME = fdf
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -MD -MP
AR = ar rcs
LIBFT = 		../library/libft/libft.a
GETNEXTLINE = 	../library/get_next_line/getnextline.a
PRINTF = 		../library/printf/printf.a
SRCS = 	fdf_array.c \
		fdf_main.c \
		fdf_map.c \
		fdf_mlx.c \
		fdf_draw.c \
		fdf_hook.c \
		fdf_legend.c \
		fdf_point.c
		
MLX_FLAGS = -lmlx -lXext -lX11
MATH_FLAGS = -lm

OBJ_DIR = object
OBJS = $(addprefix ../object/, $(SRCS:.c=.o))
DEPS = $(addprefix ../object/, $(SRCS:.c=.d))

all: $(LIBFT) $(GETNEXTLINE) $(PRINTF) $(NAME)

.SILENT:

../object/%.o: ../source/%.c 
	mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CC_FLAGS) $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT) $(GETNEXTLINE) $(PRINTF) -o $(NAME)
	printf "\r$(GREEN)✅ $(NAME) created         \n$(END)"

$(LIBFT):
	printf "\r$(GREEN)$(NAME) compiling.$(END)"
	make bonus -sC ../library/libft

$(GETNEXTLINE):
	printf "$(GREEN).$(END)"
	make -sC ../library/get_next_line

$(PRINTF):
	printf "$(GREEN).$(END)"
	make  -sC ../library/printf

clean:
	$(RM) ../object
	make clean -sC ../library/libft
	make clean -sC ../library/printf
	make clean -sC ../library/get_next_line
	printf "$(RED)🗑️  object files removed\n$(END)"

fclean: clean

	make fclean -sC ../library/libft
	make fclean -sC ../library/printf
	make fclean -sC ../library/get_next_line
	$(RM) $(NAME)
	printf "$(RED)🗑️  $(NAME) removed\n$(END)"

re: fclean all

test: all
	clear; valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-reachable=yes --show-leak-kinds=all --error-limit=no ./$(NAME)

-include $(DEPS)

.PHONY: all bonus clean fclean re