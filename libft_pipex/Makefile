# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 13:47:22 by cyferrei          #+#    #+#              #
#    Updated: 2024/04/11 14:52:20 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strncmp.c \
		ft_putstr_fd.c \
		ft_strstr.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_substr.c \
		ft_split.c \
		ft_strjoin.c \
		get_next_line.c \
		get_next_line_utils.c

NAME = libft_pipex.a
OBJS = $(SRC:.c=.o)
CC = cc
RM = rm -rf
AR = ar rcs
FLAGS = -Wall -Wextra -Werror -g3
HAEDER_FILE = libft_pipex.h

all: $(NAME)

$(NAME): $(OBJS) $(HAEDER_FILE)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re