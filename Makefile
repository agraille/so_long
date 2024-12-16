# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:58:27 by agraille          #+#    #+#              #
#    Updated: 2024/12/16 14:31:07 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC = main.c\

OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

clean :
	rm -f $(OBJ) $(BONUS_OBJ) $(DEPS)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	rm -f $(OBJ) $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"


re : fclean all

.PHONY : all bonus re fclean clean .bonus
