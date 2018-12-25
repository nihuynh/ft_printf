# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2018/12/25 02:03:18 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
SRC		:=	ft_printf.c
# directories :
SRCDIR	:=	srcs
OBJDIR	:=	objs
INCDIR	:=	includes
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra -I includes
OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INC		:=	-I $(INCDIR) -I ../lib/libft/includes
# **************************************************************************** #
all : $(NAME)
.PHONY: all
$(NAME) : $(OBJ)
	libtool -static -o $@ $(OBJ) && ranlib $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)
clean :
	rm -f $(OBJ)
	rmdir $(OBJDIR) 2> /dev/null || true
.PHONY: clean
fclean : clean
	rm -f $(NAME)
.PHONY: fclean
re : fclean all
.PHONY: re
run: all
	$(CC) $(CFLAGS) test.c -o UT_printf.out $(INC) $(NAME) ../lib/libft/libft.a
	./UT_printf.out
	rm -f UT_printf.out
.PHONY: run