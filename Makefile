#Config
CC = cc
TARGET = so_long
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L/usr/lib/X11 -lX11 -lXext -lm
INCLUDES = -I$(INC_DIR) -I$(LIBMLX_DIR)

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
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_HEADERS = $(wildcard $(LIBFT_DIR)/*.h)
LIBMLX_DIR = $(LIB_DIR)/mlx
LIBMLX = $(LIBMLX_DIR)/libmlx.a
LIBMLX_SRCS = $(wildcard $(LIBMLX_DIR)/*.c)
LIBMLX_HEADERS = $(wildcard $(LIBMLX_DIR)/*.h)

# Source + obj
SRCS = src/check_map.c src/init.c src/key.c src/loadimages.c src/map_utils.c src/paintwindows.c src/player_utils.c src/reachable.c src/so_long.c src/x11_utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main entrance
all: $(TARGET)

# Compile Binary
$(TARGET): $(OBJS) $(LIBFT) $(LIBMLX)
	@if [ -f $(TARGET) ]; then \
		echo "\033[0;33mNo changes, $(TARGET) is up to date.\033[0m"; \
	else \
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LIBMLX) $(LDFLAGS) -o $(TARGET); \
		if [ -f $(TARGET) ]; then \
			echo "\033[0;32mso_long compiled\033[0m"; \
		fi; \
	fi

# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile Libft
$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADERS)
	@if [ -f $(LIBFT) ]; then \
		echo "\033[0;33mNo changes, $(LIBFT) is up to date.\033[0m"; \
	else \
		$(MAKE) -C $(LIBFT_DIR) > /dev/null; \
		if [ -f $(LIBFT) ]; then \
			echo "\033[0;32m$@ created\033[0m"; \
		fi; \
	fi

# Compile LIBMLX
$(LIBMLX): $(LIBMLX_SRCS) $(LIBMLX_HEADERS)
	@if [ -f $(LIBMLX) ]; then \
		echo "\033[0;33mNo changes, $(LIBMLX) is up to date.\033[0m"; \
	else \
		$(MAKE) -C $(LIBMLX_DIR) > /dev/null; \
		if [ -f $(LIBMLX) ]; then \
			echo "\033[0;32m$@ created\033[0m"; \
		fi; \
	fi

# Utils
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;32mObjects deleted\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@echo "\033[0;32mlibft deleted\033[0m"
	@$(MAKE) -C $(LIBMLX_DIR) clean > /dev/null
	@echo "\033[0;32mmlx deleted\033[0m"

fclean: clean
	@rm -rf $(TARGET) > /dev/null
	@echo "\033[0;32mso_long binary deleted\033[0m"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
