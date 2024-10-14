# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBS = utils.h

# Directories
SRC_DIR = .
UTILS_DIR = utils

# Source files
SRC = $(SRC_DIR)/push_swap.c $(UTILS_DIR)/ft_atoi.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = a.out

# Default target
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJ)

# Remove the executable
fclean: clean
	rm -f $(EXEC)

# Rebuild the project
re: fclean all

# PHONY targets
.PHONY: all clean fclean re
