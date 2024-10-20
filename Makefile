# Define directories
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a  # Path to the libft static library

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Include header files
INCLUDES = -I. -I$(LIBFT_DIR)  # '.' for current directory and libft directory for headers

SRC = $(wildcard *.c) #automatically includes all .c files into source

# Object files (convert .c files to .o files)
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = push_swap

# Default target
all: $(EXEC)

# Rule to create the executable, linking with libft.a
$(EXEC): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(EXEC)

# Rule to compile source files into object files in the current directory
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create libft.a if it doesn't exist
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(EXEC)
	rm -f $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
