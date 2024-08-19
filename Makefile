#Config
CC = cc
TARGET = SO_LONG
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LDFLAGS = -L/usr/local/lib -lmlx -lX11 -lXext -lm
INCLUDES = -I/usr/local/include -I$(INC_DIR)

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

all: $(TARGET)

$(TARGET): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(TARGET) $(LIBFT)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: all clean fclean $(LIBFT)
