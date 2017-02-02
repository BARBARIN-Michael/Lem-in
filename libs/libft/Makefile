#*************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/01 12:40:31 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CFLAGS += -O3 -Wall -Wextra -Werror -I ./include/ -I ./../libftprintf/include
ifeq ($(DEBUG), true)
	CFLAGS += -pg
endif

SRCS = 	src/ft_bzero.c			\
		src/ft_memcpy.c		\
		src/ft_memccpy.c		\
		src/ft_memmove.c		\
		src/ft_memchr.c		\
		src/ft_memcmp.c		\
		src/ft_strlen.c		\
		src/ft_strdup.c		\
		src/ft_strcpy.c		\
		src/ft_strncpy.c		\
		src/ft_strcat.c		\
		src/ft_strncat.c		\
		src/ft_strlcat.c		\
		src/ft_strchr.c		\
		src/ft_findchr.c		\
		src/ft_strrchr.c		\
		src/ft_strstr.c		\
		src/ft_strchange.c		\
		src/ft_strcmp.c		\
		src/ft_strncmp.c		\
		src/ft_strnew.c		\
		src/ft_strdel.c		\
		src/ft_strclr.c		\
		src/ft_striter.c		\
		src/ft_striteri.c		\
		src/ft_strmap.c		\
		src/ft_strmapi.c		\
		src/ft_strequ.c		\
		src/ft_strnequ.c		\
		src/ft_strsub.c		\
		src/ft_strjoin.c		\
		src/ft_strjoin_free.c	\
		src/ft_strtrim.c		\
		src/ft_strsplit.c		\
		src/ft_strtol.c		\
		src/ft_atoi.c			\
		src/ft_isalpha.c		\
		src/ft_isdigit.c		\
		src/ft_isalnum.c		\
		src/ft_isascii.c		\
		src/ft_isprint.c		\
		src/ft_isspace.c		\
		src/ft_strisuporlow.c	\
		src/ft_toupper.c		\
		src/ft_tolower.c		\
		src/ft_count_carac.c	\
		src/ft_memalloc.c		\
		src/ft_memdel.c		\
		src/ft_memset.c		\
		src/ft_realloc.c		\
		src/ft_itoa.c			\
		src/ft_putchar.c		\
		src/ft_putstr.c		\
		src/ft_putstr_c.c		\
		src/ft_putendl.c		\
		src/ft_putnbr.c		\
		src/ft_putchar_fd.c	\
		src/ft_putstr_fd.c		\
		src/ft_putendl_fd.c	\
		src/ft_lstnew.c		\
		src/ft_lstdelone.c		\
		src/ft_lstdel.c		\
		src/ft_lstadd.c		\
		src/ft_lstadd_back.c	\
		src/ft_lstiter.c		\
		src/ft_lstmap.c		\
		src/ft_lstnew.c		\
		src/ft_replace.c		\
		src/ft_round.c			\
		src/ft_insert.c		\
		src/get_nbr_line.c		\
		src/get_next_line.c	\
		src/ft_array_count.c	\
		src/ft_pow.c			\
		src/ft_ntoa.c			\
		src/ft_strset.c		\
		src/ft_wtoa.c			\
		src/ft_tabcpy.c		\
		src/ft_strisempty.c	\
		src/ft_log.c


OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

PINC = include/

INC = $(PINC)def.h $(PINC)ft_checking.h $(PINC)get_next_line.h $(PINC)libft.h

RM = rm -f

all: obj $(NAME)

obj:
	mkdir -p $@

obj/%.o: src/%.c $(INC)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) -rsc $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

fcleanall: fclean
	$(RM) $(EXE)

re: fclean all

.PHONY: fclean obj all fcleanall clean
