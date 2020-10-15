# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 18:10:56 by nihuynh           #+#    #+#              #
#    Updated: 2020/10/15 19:36:56 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
RUNMODE	?=	dev
SRC		:=	ft_printf.c ft_itob_base.c ft_lltob_base.c
SRC		+=	form_unknown.c form_percent.c form_integer.c form_unsigned.c\
			form_octal.c form_hexa.c form_float.c form_character.c\
			form_string.c form_pointer.c mod_1.c mod_2.c
SRC		+=	ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_memset.c ft_isspace.c\
			ft_strlen.c ft_atoi.c ft_isdigit.c ft_isblank.c ft_strncpy.c
# directories :
SRCDIR	:=	srcs
OBJDIR	:=	objs
INCDIR	:=	includes
# **************************************************************************** #
# Compile custom :
CC			:=	clang
CFLAGS		:=	-Werror -Wall -Wextra -Wstrict-aliasing -pedantic -Wunreachable-code
.SUFFIXES:
ifeq ($(RUNMODE),dev)
DEV_CFLAGS	:=	-g3 -O0
# DEV_CFLAGS	+=	-fsanitize=thread
# DEV_CFLAGS	+=	-fsanitize=address -fsanitize-recover=address
# DEV_CFLAGS	+=	-fstack-protector
# DEV_CFLAGS	+=	-fsanitize=undefined
else
DEV_CFLAGS	:= -O3 -march=native -flto -g0
endif
CFLAGS		+= $(DEV_CFLAGS)

NORME	:= ~/.norminette/norminette.rb
OBJ		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP		:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.d))
INC		:=	-I $(INCDIR)
# **************************************************************************** #
OKLOGO		:=	\033[80G\033[32m[OK]\033[0m\n
GREP_ERR	:=	grep 'Error\|Warning' -C1 2> /dev/null && exit 1 || true
# **************************************************************************** #
all : $(NAME)
.PHONY: all
$(NAME) : $(OBJ)
	libtool -static -o $@ $(OBJ) && ranlib $@
-include $(DEP)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c -MMD -MP -o $@ $< $(INC)
clean :
	rm -f $(OBJ)
	rm -f $(DEP)
	rm -f UT_printf.out
	rmdir $(OBJDIR) 2> /dev/null || true
.PHONY: clean
fclean : clean
	rm -f $(NAME)
.PHONY: fclean
re : fclean all
.PHONY: re
norme:
	$(NORME) srcs includes | $(GREP_ERR)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme
test: all
	@$(CC) $(CFLAGS) test.c -o UT_printf.out $(INC) $(NAME)
	@./UT_printf.out
.PHONY: run
curqui: re
	@rm -rf ../curqui_test/libftprintf.a && cp libftprintf.a ../curqui_test
	@make -C ../curqui_test
	@-./../curqui_test/ft_printf_tests
.PHONY: curqui
