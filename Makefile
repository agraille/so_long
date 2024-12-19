# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 10:58:27 by agraille          #+#    #+#              #
#    Updated: 2024/12/19 12:19:47 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC = src/main.c src/window.c src/utils.c src/parsing.c src/flood_fill.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

MLX_DIR = ./minilibx
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_SRC = $(wildcard $(MLX_DIR)/*.c)
MLX_OBJ = $(MLX_SRC:.c=.o)
MLX_FLAGS = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX)

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*/*.c)
LIBFT_HEADERS = $(wildcard $(LIBFT_DIR)/include/*.h)
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT_FLAGS = -L$(LIBFT_DIR) $(LIBFT_A)

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Succes! ✅  ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

$(MLX): $(MLX_SRC)
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT_A): $(LIBFT_SRC) $(LIBFT_HEADERS)
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: %.c Makefile ./include/so_long.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -I $(MLX_DIR) -c $< -o $@


clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all

.PHONY : all re fclean clean
