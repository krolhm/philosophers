# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 20:42:51 by rbourgea          #+#    #+#              #
#    Updated: 2021/05/29 11:28:28 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo_two

SRCS =		srcs/main.c \
			srcs/routine.c \
			srcs/errors.c \
			srcs/parsing.c \
			srcs/print.c \
			srcs/utils.c \
			srcs/libft.c \
			srcs/libft2.c

OBJS = 		$(SRCS:%.c=%.o)

CFLAGS =	-g -Wall -Wextra -Werror -pthread 

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
