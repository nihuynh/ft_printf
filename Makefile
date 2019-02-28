# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2019/02/28 15:57:00 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
SRC		:=	ft_printf.c ft_itob_base.c
SRC		+=	form_unknown.c form_percent.c form_integer.c form_unsigned.c\
			form_octal.c form_hexa.c form_float.c form_character.c\
			form_string.c form_pointer.c
SRC		+=	ft_bzero.c ft_memcpy.c ft_strlcpy.c\
			ft_strlen.c
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
OKLOGO		:=	\033[80G\033[32m[OK]\033[0m\n
GREP_ERR	:=	grep 'Error\|Warning' -C1 2> /dev/null || true
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
norme:
	norminette -R CheckForbiddenSourceHeader srcs includes | $(GREP_ERR)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme
run: all
	$(CC) $(CFLAGS) test.c -o UT_printf.out $(INC) $(NAME)
	./UT_printf.out
.PHONY: run