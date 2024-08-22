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
LIBMLX_DIR = $(LIB_DIR)/mlx
LIBMLX = $(LIBMLX_DIR)/libmlx.a

# Source + obj
SRCS = src/check_map.c src/init.c src/key.c src/loadimages.c src/map_utils.c src/paintwindows.c src/player_utils.c src/reachable.c src/so_long.c src/x11_utils.c
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main entrance
all: libft libmlx $(TARGET)

# Compile Binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(LIBMLX) $(LDFLAGS) -o $(TARGET)

# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Lib Rules
libft:
	@$(MAKE) --silent --no-print-directory -C $(LIBFT_DIR)

libmlx:
	@$(MAKE) --silent --no-print-directory -C $(LIBMLX_DIR)

# Utils
clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;32mObjects deleted\033[0m"
	@$(MAKE) --silent -C $(LIBFT_DIR) fclean
	@echo "\033[0;32mlibft deleted\033[0m"
	@$(MAKE) --silent -C $(LIBMLX_DIR) clean
	@echo "\033[0;32mmlx deleted\033[0m"

fclean: clean
	@rm -rf $(TARGET)
	$(MAKE) --silent -C $(LIBFT_DIR) fclean
	@echo "\033[0;32mso_long binary deleted\033[0m"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
