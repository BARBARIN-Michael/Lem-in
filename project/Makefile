# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:55:33 by mbarbari          #+#    #+#              #
#    Updated: 2017/02/02 17:31:21 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= gcc
CX ?= clang++

CFLAGS += -g -Wall -Wextra -Werror

INC = -I./inc -I../libs/libft/include -I../libs/libftstream/include
LIBS = -L../libs/libft/ -L../libs/libftstream/ -lft -lftstream

CLI_SRCS = 	src/link.c \
			src/main.c \
			src/parser_room.c \
			src/testing.c \
			src/algo.c \
			src/way.c \
    		src/main.c

CLI_OBJS = $(patsubst src/%.c,obj/%.o,$(CLI_SRCS))

SRC_INCLUDE = ./inc/*.h \

RM ?= rm -f
MKDIR ?= mkdir

all: lem_in

print-% : ; $(info $* is $(flavor $*) variable set to [$($*)]) @true

lem_in: $(CLI_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LIBS)

obj/%.o: src/%.c $(SRC_INCLUDE)
	$(MKDIR) -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	$(RM) $(CLI_OBJS)

fclean: clean
	$(RM) cli
	$(RM) $(CLI_OBJS)

re: fclean all

.PHONY: clean fclean re all
