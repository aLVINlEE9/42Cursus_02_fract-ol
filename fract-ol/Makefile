# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 00:04:04 by seungsle          #+#    #+#              #
#    Updated: 2022/02/10 20:32:01 by seungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
CFLAG	= -O3 -Werror -Wall -Wextra
FFLAG	= -framework OpenGL -framework AppKit
SRCS 	=	srcs/check_valid.c		\
			srcs/fractol.c			\
			srcs/ft_putstr_fd.c		\
			srcs/init_1.c			\
			srcs/listener.c			\
			srcs/mouse_listener.c	\
			srcs/pxl_to_img.c		\
			srcs/execute.c			\
			srcs/ft_itoa.c			\
			srcs/ft_strncmp.c		\
			srcs/init_2.c			\
			srcs/main.c				\
			srcs/print_error.c		\
			srcs/ft_atod.c			\
			srcs/parsing_num.c

OBJS 	= ${SRCS:.c=.o}
INCLUDE	= -I./includes/ -L./mlx -lmlx

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAG) $(OBJS) $(INCLUDE) $(FFLAG) -o $(NAME)

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re