# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pnoutere <pnoutere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:46:59 by pnoutere          #+#    #+#              #
#    Updated: 2022/05/18 18:22:50 by pnoutere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = libftprintf.a
SRCS = ft_printf.c ft_itoa_base.c floats.c ints.c helpers.c hexadecimals.c handlers.c \
checkers.c utils.c pre_flag_checks.c initiators.c padding_utility.c ft_ftoa.c strings.c bonuses.c \
ft_ftoa_utility.c binary.c
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3 -c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)

re : fclean all