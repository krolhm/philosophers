# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 19:22:14 by rbourgea          #+#    #+#              #
#    Updated: 2021/05/30 19:23:30 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo_three

SRCS =		srcs/main.c \
			srcs/routine.c \
			srcs/errors.c \
			srcs/parse.c \
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
