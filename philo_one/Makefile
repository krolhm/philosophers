# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:56:20 by rbourgea          #+#    #+#              #
#    Updated: 2021/05/28 20:42:33 by rbourgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		philo_one

SRCS =		srcs/main.c \
			srcs/routine.c \
			srcs/utils.c \
			srcs/print.c \
			srcs/errors.c \
			srcs/libft.c \
			srcs/libft2.c

OBJS =		$(SRCS:%.c=%.o)

CFLAGS =	-g -Wall -Wextra -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
