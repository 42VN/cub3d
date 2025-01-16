# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:21:50 by hitran            #+#    #+#              #
#    Updated: 2025/01/16 11:08:49 by hitran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC 				= cc
CFLAGS 			= -Wall -Wextra -Werror
MLX42_FLAGS		= -ldl -lglfw -pthread -lm
INCLUDES 		= -I./includes -I./mylib/includes -I./MLX42/include/MLX42
RM 				= rm -rf

# Directories
MYLIB_DIR	 	= ./mylib
MLX42_DIR		= ./MLX42
SRC_DIR			= ./sources
MAN_DIR 		= $(SRC_DIR)/mandatory
BN_DIR			= $(SRC_DIR)/bonus
MAP_DIR			= map
UTILS_DIR		= utils

# Source files by directory
MAN_FILES 		= 	read_map.c	read_line.c errors.c

BN_FILES 		= 	

MAN_SRCS		= 	$(SRC_DIR)/main.c 	$(addprefix $(MAN_DIR)/, $(MAN_FILES)) 

BN_SRCS			= 	main_bonus.c 	$(addprefix $(BN_DIR)/, $(BN_FILES)) 

# Library
MYLIB 			= $(MYLIB_DIR)/mylib.a
MLX42			= $(MLX42_DIR)/build/libmlx42.a

# Executables
NAME 			= cub3D

# Targets
all : mandatory

mandatory : .mandatory
.mandatory: $(MYLIB) $(MLX42) $(MAN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAN_SRCS) $(MYLIB) $(MLX42) $(MLX42_FLAGS) -o $(NAME)
	@touch .mandatory
	@$(RM) .bonus

bonus: .bonus
.bonus: $(MYLIB) $(MLX42) $(BN_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BN_SRCS) $(MYLIB) $(MLX42) $(MLX42_FLAGS) -o $(NAME)
	@touch .bonus
	@$(RM) .mandatory

$(MYLIB):
	$(MAKE) -C $(MYLIB_DIR)

$(MLX42): .mlx42
.mlx42: 
	@$(RM) $(MLX42_DIR)
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
	@cd $(MLX42_DIR) && mkdir -p build && cd build && cmake .. && cmake --build . -j4
	@cd ..
	@$(RM) $(MLX42_DIR)/.git
	@touch .mlx42

clean:
	$(MAKE) clean -C $(MYLIB_DIR)
	$(RM) .bonus .mandatory $(MLX42_DIR)/build

fclean: clean
	$(MAKE) fclean -C $(MYLIB_DIR)
	$(RM) $(NAME) $(MLX42_DIR) .bonus .mandatory .mlx42
	
re: fclean all

.PHONY: all clean fclean re mandatory bonus