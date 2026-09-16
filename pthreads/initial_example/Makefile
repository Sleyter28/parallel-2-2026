# --- Compiler and Flags ---
CC        := gcc
CFLAGS    := -Wall -Wextra -std=c23 -g -pthread
CPPFLAGS  := -Iinclude -MMD -MP # Auto-dependency tracking & include directory

# --- Directories ---
SRC_DIR   := src
OBJ_DIR   := obj
BIN_DIR   := bin

# --- Target Executable ---
EXE       := $(BIN_DIR)/my_program

# --- File Discovery ---
# Find all .c files in src/
SRCS      := $(wildcard $(SRC_DIR)/*.c)
# Translate src/filename.c to obj/filename.o
OBJS      := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
# Generate dependency file names (.d)
DEPS      := $(OBJS:.o=.d)

# --- Primary Targets ---
.PHONY: all clean

all: $(EXE)

# Link object files into the final executable
$(EXE): $(OBJS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Compile source files into object files
# Note: The line below must start with a literal TAB character, not spaces
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Create output directories if they do not exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Include compiler-generated dependency files (handles header changes)
-include $(DEPS)

# Clean up build artifacts
# Note: The line below must start with a literal TAB character, not spaces
clean:
	@rm -rvf $(OBJ_DIR) $(BIN_DIR)

run: $(EXE)
	@./$(EXE)
