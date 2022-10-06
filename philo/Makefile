# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikalakhi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 20:59:17 by ikalakhi          #+#    #+#              #
#    Updated: 2022/10/02 18:46:06 by ikalakhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c philo_utils.c philo_errors.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)
$(NAME): $(OBJS)
	cc  $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
