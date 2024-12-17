# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:58:27 by agraille          #+#    #+#              #
#    Updated: 2024/12/17 10:49:47 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC = main.c init_and_free.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) -g
	
all: $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile ./include/so_long.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I . -I $(MLX_DIR) -c $< -o $@
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

clean :
	rm -rf $(OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean : clean
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all

.PHONY : all re fclean clean
