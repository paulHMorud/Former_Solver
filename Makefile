# Variables
CC = gcc                     # Compiler
CFLAGS = -Wall -Wextra -g    # Compiler flags
TARGET = myprogram           # Output program name
SRC = main.c board.c       # Source files
OBJ = $(SRC:.c=.o)           # Object files

# Default rule (first target is the default)
all: $(TARGET)

# Rule to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove build files
clean:
	rm -f $(OBJ) $(TARGET)
