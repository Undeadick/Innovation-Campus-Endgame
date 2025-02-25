# Compiler and flags
CC := clang
CFLAGS := -std=c11 -Wall -Werror -Wextra -Wpedantic -ggdb3 -O0 -Iinc -Iresource/libs/include/SDL2
LIBS := -Lresource/libs/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lm

# Directories
SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
EXEC := endgame

# Source files and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(EXEC)

# Linking the executable
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

# Rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Uninstall target
uninstall: clean
	rm -f $(EXEC)

# Rebuild everything
reinstall: uninstall all

.PHONY: all clean uninstall reinstall
