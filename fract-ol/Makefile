# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsle <seungsle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 00:04:04 by seungsle          #+#    #+#              #
#    Updated: 2022/02/03 08:46:01 by seungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc -O3
CFLAG	= -Werror -Wall -Wextra
FFLAG	= -framework OpenGL -framework AppKit
TARGET	= fractol
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
			srcs/print_error.c

OBJS 	= ${SRCS: %.c=%.o}
INCLUDE	= -I./includes/ -L./mlx -lmlx

$(TARGET) :
	$(CC) $(CFLAG) $(OBJS) $(INCLUDE) $(FFLAG) -o $(TARGET)

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all