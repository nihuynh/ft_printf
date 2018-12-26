# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2018/12/26 03:30:42 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
SRC		:=	ft_printf.c ft_itob_base.c
SRC		+=	ft_bzero.c ft_itoa.c ft_memcpy.c ft_strlcpy.c\
			ft_strlen.c ft_strnew.c ft_strdel.c
# directories :
SRCDIR	:=	srcs
OBJDIR	:=	objs
INCDIR	:=	includes
# **************************************************************************** #
CC		:=	clang
CFLAGS	:=	-Werror -Wall -Wextra -I includes
OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INC		:=	-I $(INCDIR)
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
	rm -f UT_printf.out
	rmdir $(OBJDIR) 2> /dev/null || true
.PHONY: clean
fclean : clean
	rm -f $(NAME)
.PHONY: fclean
re : fclean all
.PHONY: re
run: all
	$(CC) $(CFLAGS) test.c -o UT_printf.out $(INC) $(NAME)
	./UT_printf.out
.PHONY: run