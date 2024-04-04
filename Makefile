# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:46:01 by cyferrei          #+#    #+#              #
#    Updated: 2024/04/04 14:07:04 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -rf
CFLAGS = -Werror -Wextra -Werror -g3
LIBFT_PIPEX_PATH = libft_pipex/
LIBFT_PIPEX = libft_pipex/libft_pipex.a 

BOLD    = \e[1m
FADE    = \e[2m
ITA     = \e[3m
BLINK   = \e[5m
GREEN   = \e[38;5;76m
RED     = \e[38;5;196m
YELLOW  = \e[38;5;227m
ORANGE  = \e[38;5;208m
PURPLE  = \e[38;5;201m
LBLUE   = \e[38;5;45m
BLUE    = \e[38;5;27m
INDI    = \e[38;5;91m
SPINK   = \e[38;5;225m
PEACH   = \e[38;5;223m
GREY    = \e[38;5;254m
RESET   = \e[00m

SOURCE = ./sources/
MAIN = pipex.c pipex_utils.c
PIPEX = $(addprefix $(SOURCE), $(MAIN))

SRC = $(PIPEX)
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BOLD)Linking...$(RESET)"
	@make -sC $(LIBFT_PIPEX_PATH)
	$(RM) $(NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PIPEX) -o $(NAME)
	@echo "$(GREEN)Executable '$(NAME)' created successfully!$(RESET)"

%.o: %.c
	@echo "$(BOLD)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$@ compiled successfully!$(RESET)"

clean:
	@echo "$(BOLD)Cleaning object files...$(RESET)"
	$(RM) $(OBJS)
	@make -s clean -C $(LIBFT_PIPEX_PATH)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean
	@echo "$(BOLD)Cleaning executable...$(RESET)"
	@make -s fclean -C $(LIBFT_PIPEX_PATH)
	$(RM) $(NAME)
	@echo "$(GREEN)Executable cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean re