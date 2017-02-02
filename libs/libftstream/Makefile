#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Make                                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 14:48:04 by mbarbari          #+#    #+#              #
#    Updated: 2017/01/17 14:46:28 by barbare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftstream.a
CC = gcc

OBJDIR = ./obj

LIBS = -L../libft/ -lft 
INC =  -I ../libft/include/

CFLAGS += -Wall -Wextra -Werror -I ./include/ $(INC)

SRCS = 	src/ft_stream_new.c			\
		src/ft_stream_cursor.c		\
		src/ft_stream_get.c			\
		src/ft_stream_read.c		\
		src/ft_stream_reset.c

LIBFT_PATH ?= ../libft/

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT_PATH)/libft.a $(OBJS) 
	$(CP) $(LIBFT_PATH)/libft.a $(NAME)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
