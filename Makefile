# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:46:01 by cyferrei          #+#    #+#              #
#    Updated: 2024/04/16 18:16:42 by cyferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
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
SOURCE_BONUS = ./sources_bonus/
MAIN = pipex.c pipex_utils.c children_cmd.c
MAIN_BONUS = pipex_bonus.c pipex_utils_bonus.c children_process.c children_process_utils.c
PIPEX = $(addprefix $(SOURCE), $(MAIN))
PIPEX_BONUS = $(addprefix $(SOURCE_BONUS), $(MAIN_BONUS))

SRC = $(PIPEX)
SRC_BONUS = $(PIPEX_BONUS)
OBJS = $(SRC:%.c=%.o)
OBJS_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@echo "$(BOLD)Linking...$(RESET)"
	@make -sC $(LIBFT_PIPEX_PATH)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PIPEX) -o $(NAME_BONUS)
	@echo "$(GREEN)Executable bonus'$(NAME_BONUS)' created successfully!$(RESET)"

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
	$(RM) $(OBJS_BONUS)
	@make -s clean -C $(LIBFT_PIPEX_PATH)
	@echo "$(GREEN)Object files cleaned successfully!$(RESET)"

fclean: clean 
	@echo "$(BOLD)Cleaning executable...$(RESET)"
	@make -s fclean -C $(LIBFT_PIPEX_PATH)
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Executable cleaned successfully!$(RESET)"

re: fclean all

.PHONY: all clean fclean bonus re