# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/01/16 10:49:04 by baavril          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\
	   gestion_conv1_printf.c\
	   gestion_conv2_printf.c\
	   gestion_conv3_printf.c\
	   gestion_parsing_printf.c\
	   gestion_parsing2_printf.c\
	   gestion_de_crise.c\
	   gestion_t_pattern.c\


SRCS_PATH = $(addprefix &(SRCDIR),$(SRCS))

OBJ = $(SRCS_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -Ofast -c $< -I ./includes/ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
