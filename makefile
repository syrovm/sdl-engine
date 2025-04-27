PROJECT_ROOT := $(shell pwd)
GAME_DIR := src/game
ENGINE_DIR := src/engine
MAIN_PATH := src/main.c

OUTPUT_DIR := build

EXTERNAL_DEPENDENCY_PATHS := /usr/include/SDL2

CC = clang

# Compiler and linker flags
ENGINE_DIRS = $(shell find $(ENGINE_DIR) -type d)
GAME_DIRS = $(shell find $(GAME_DIR) -type d)

CFLAGS = $(foreach dir,$(ENGINE_DIRS),-I$(dir)) $(foreach dir,$(GAME_DIRS),-I$(dir)) $(foreach dir,$(EXTERNAL_DEPENDENCY_PATHS),-I$(dir)) -Wall -g 
LDFLAGS = -lSDL2 -lSDL2_image

# Paths
LIBRARY_PATHS = -L$(ENGINE_DIR) -L$(GAME_DIR)

# Source files
SRCS = $(wildcard $(foreach dir,$(ENGINE_DIRS),$(dir)/*.c) $(foreach dir,$(GAME_DIRS),$(dir)/*.c) $(MAIN_PATH))

# Generate names of object files
OBJS = $(SRCS:.c=.o)

# Name of executable
EXEC = $(OUTPUT_DIR)/main

# Default recipe
all: $(EXEC)

# Recipe for building the final executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LIBRARY_PATHS) -o $@

# Recipe for building object files
$(OBJS): %.o: %.c
	@echo "Building $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
# Recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
