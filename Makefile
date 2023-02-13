# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvebers <kvebers@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 12:20:09 by kvebers           #+#    #+#              #
#    Updated: 2023/02/12 17:32:31 by kvebers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CFLAGS	= -Wall -Wextra -Werror
CC		= cc
SRC	=	src/philo.c src/atoi.c src/atoi_utils.c src/free.c
RM = 		rm -f
SRC_O	= $(SRC:%.c=%.o)

all:  $(NAME)

$(NAME): $(SRC_O)
	$(CC) $(CFLAGS) $(SRC_O) -o $(NAME)

clean:
	- @$(RM) $(SRC_O)

fclean: clean
	- @$(RM) ${NAME}

re: fclean all

.PHONY: clean fclean all re
