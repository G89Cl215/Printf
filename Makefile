# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baavril <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 10:37:50 by baavril           #+#    #+#              #
#    Updated: 2019/01/31 13:47:37 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libftprintf.a

PTF_PATH    =   printf

HDR     =   $(PTF_PATH)/ft_printf.h \
			$(PTF_PATH)/g_convtab.h \
			$(PTF_PATH)/float_conv_tools.h \

LIB_PATH    =   libft

LIB     =   $(LIB_PATH)/libft.a

DIR_O   =   temporary

SOURCES =   ft_printf.c \
			extract_from_pattern.c \
			float_conv_tools.c \
			conv_char_printf.c \
			conv_float1_printf.c \
			conv_float2_printf.c \
			conv_int_printf.c \
			conv_ubase_printf.c \
			conv_unicode_printf.c \
			gestion_de_crise_printf.c \
			gestion_padding1.c \
			gestion_padding2_prec.c \
			gestion_padding3_flags.c \
			gestion_padding4_float.c \
			gestion_padding5_flags.c \
			gestion_padding6_flags.c \
			gestion_t_pattern.c \
			parsing_pattern_detect.c \
			parsing_extract_pattern.c \
			parsing_pos1.c \
			parsing_pos2.c \
			pattern_to_conv.c \

SRCS    =   $(addprefix $(PTF_PATH)/,$(SOURCES))

OBJS    =   $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

CC      =   gcc

CFLAGS  =   -Wall -Werror -Wextra

RM      =   rm -f

CLEAN   =   clean

all     :   $(NAME)

$(LIB)  :
	@make -C $(LIB_PATH)

$(NAME) :   $(OBJS) $(LIB) $(HDR) Makefile
	@cp $(LIB) ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "libftprintf.a has been successfully created."

$(DIR_O)/%.o: $(PTF_PATH)/%.c
	@mkdir -p temporary
	@$(CC) -I $(PTF_PATH) -o $@ -c $<

clean   :
	@$(RM) $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIB_PATH)
	@echo "All .o files have been deleted."

fclean  :   clean
	@$(RM) $(NAME) $(LIB)
	@echo "libftprintf.a and libft.a has been deleted."

re      :   fclean all

.PHONY: all clean fclean re
