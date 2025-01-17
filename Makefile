# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 12:21:50 by hitran            #+#    #+#              #
#    Updated: 2025/01/16 17:37:53 by ktieu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC 				= cc
CFLAGS 			= -g
MLX42_FLAGS		= -ldl -lglfw -pthread -lm
INCLUDES 		= -I./includes -I./libs/libft -I./libs/MLX42/include/MLX42
RM 				= rm -rf

# Directories
SRC_DIR 			= srcs
LIB_DIR 			= libs
OBJ_DIR				= obj
LIB_DIR 			= libs
LIBFT_DIR	 		= $(LIB_DIR)/libft
MLX42_DIR			= $(LIB_DIR)/MLX42
MAP_DIR				= ./assets/map
UTILS_DIR			= $(SRC_DIR)/utility
CUB3D_DIR			= $(SRC_DIR)/cub3d
ASSET_MANAGER_DIR	= $(SRC_DIR)/asset_manager


# Source files by directory
CUB3D_FILES			=	init.c
UTIL_FILES			=	ft_error_ret.cc
ASSET_MANAGER_FILES	=	am_load_png.c

SRC_FILES		= 	./srcs/main.c \
					$(addprefix $(CUB3D_DIR)/, $(CUB3D_FILES)) \
					$(addprefix $(UTILS_DIR)/, $(UTIL_FILES)) \
					$(addprefix $(ASSET_MANAGER_DIR)/, $(ASSET_MANAGER_FILES)) 

# Library
LIBFT 			= $(LIBFT_DIR)/libft.a
MLX42			= $(MLX42_DIR)/build/libmlx42.a

# Executables
NAME 			= cub3D

# Targets
all : mandatory

mandatory : .mandatory
.mandatory: $(LIBFT) $(MLX42) $(SRC_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC_FILES) $(LIBFT) $(MLX42) $(MLX42_FLAGS) -o $(NAME)
	@touch .mandatory
	@$(RM) .bonus


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42): .mlx42
.mlx42: 
	@$(RM) $(MLX42_DIR)
	@git clone https://github.com/codam-coding-college/MLX42.git $(MLX42_DIR)
	@cd $(MLX42_DIR) && mkdir -p build && cd build && cmake .. && cmake --build . -j4
	@cd ..
	@$(RM) $(MLX42_DIR)/.git
	@touch .mlx42

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) .bonus .mandatory $(MLX42_DIR)/build

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(MLX42_DIR) .bonus .mandatory .mlx42
	
re: fclean all

.PHONY: all clean fclean re mandatory 