# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42barcelona.fr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 12:22:33 by shurtado          #+#    #+#              #
#    Updated: 2024/08/23 20:48:14 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Config
CC = cc
TARGET = so_long
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L/usr/lib/X11 -lX11 -lXext -lm
INCLUDES = -I$(INC_DIR) -I$(LIBMLX_DIR) -I$(LIBFT_DIR)/include

# Debug
#CFLAGS += -g -O1 -fsanitize=address
# Directory
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIB_DIR = lib

# Librarys
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = $(LIB_DIR)/mlx
LIBMLX = $(LIBMLX_DIR)/libmlx.a

# Source + obj
SRCS_FILES = check_map.c init.c key.c loadimages.c map_utils.c paintwindows.c player_utils.c reachable.c so_long.c x11_utils.c
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_FILES))

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main entrance
all: libft libmlx $(TARGET)

# Compile Binary
$(TARGET): $(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LIBMLX) $(LDFLAGS) -o $(TARGET)
	@echo "\033[1;36mBinary $@ created\033[0m"


# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist.make
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Lib Rules
libft:
	@$(MAKE) --silent --no-print-directory -C $(LIBFT_DIR)

libmlx:
	@$(MAKE) --silent --no-print-directory -C $(LIBMLX_DIR) > /dev/null

# Utils
clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "\033[1;31mObjects deleted\033[0m"; \
	fi
	@$(MAKE) --silent --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --silent --no-print-directory -C $(LIBMLX_DIR) clean > /dev/null
	@echo "\033[1;33mmlx clean instruction sent\033[0m"

fclean: clean
	@if [ -f "$(TARGET)" ]; then \
		rm -f $(TARGET); \
		echo "\033[1;31m$(TARGET) deleted\033[0m"; \
	fi


re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
