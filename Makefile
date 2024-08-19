#Config
CC = cc
TARGET = SO_LONG
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/local/lib -lmlx -lX11 -lXext -lm
INCLUDES = -I/usr/local/include -I$(INC_DIR)

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

# Source + obj
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Main entrance
all: $(TARGET)

# Compile Binary
$(TARGET): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBFT) > /dev/null
	@echo "\033[0;32mSO_LONG compiled\033[0m"

# -MMD to include header dependences to .d file and run $(OBJ_DIR) if not exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -c $< -o $@ > /dev/null
	@echo "\033[0;32mObject $@ created\033[0m"

# Create obj dir
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "\033[0;32mlibft.a compiled\033[0m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[0;32mObjects deleted\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@echo "\033[0;32mlibft/objects deleted\033[0m"

fclean: clean
	@rm -rf $(TARGET) > /dev/null
	@echo "\033[0;32mSO_LONG deleted\033[0m"
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re $(LIBFT)
