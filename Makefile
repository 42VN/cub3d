# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hitran <hitran@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:21:50 by hitran            #+#    #+#              #
#    Updated: 2025/01/20 14:45:42 by hitran           ###   ########.fr        #
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

MAP_DIR			= $(SRC_DIR)/map
ERROR_DIR		= $(SRC_DIR)/errors
UTILS_DIR		= $(SRC_DIR)/utils

# Source files by directory
MAP_FILES 		= 	read_map.c	read_element.c read_file.c 

ERROR_FILES 	= 	map_errors.c

UTILS_FILES 	= 	read_line.c set_color.c print_map.c validate_path.c \
					clean_game.c

BN_FILES 		= 	

MAN_SRCS		= 	$(SRC_DIR)/main.c 	\
					$(addprefix $(MAP_DIR)/, $(MAP_FILES)) \
					$(addprefix $(ERROR_DIR)/, $(ERROR_FILES)) \
					$(addprefix $(UTILS_DIR)/, $(UTILS_FILES))					

BN_SRCS			= 	

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