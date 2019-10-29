# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czhang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 19:51:13 by czhang            #+#    #+#              #
#    Updated: 2019/10/29 20:37:33 by czhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

LIB = libft/libft.a

FILE =	main.c\
		draw.c\
		key_esc.c\
		mandelbrot.c\
		#get_next_line.c\
		parse.c\
		#resize.c\
		tab_type.c\
		coord.c\#

INC = -I libft/includes

SRC = $(FILE:%=%)

OBJ = $(FILE:%.c=objs/%.o)

FLAG = #-Wall -Werror -Wextra

CC = gcc $(FLAG) $(INC)

RM = rm -f

all: $(NAME)

$(NAME) : $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework Appkit

$(LIB) :
	make -C libft/ all

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(INC) -o $@ -c $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
