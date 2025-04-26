CC = clang

# Compiler and linker flags
ENGINE_INCLUDES = $(shell find $(./engine) -type d)
GAME_INCLUDES = $(shell find $(./game) -type d)
CFLAGS = $(foreach dir,$(ENGINE_INCLUDES),-I$(dir)) $(foreach dir,$(GAME_INCLUDES),-I$(dir)) -I/usr/include/SDL2 -Wall -g # Add -O2 for release builds
LDFLAGS = -lSDL2 -lSDL2_image

# Paths
LIBRARY_PATHS = -Lengine -Lgame

# Source files
SRCS = $(wildcard engine/*.c game/systems/**/*.c game/systems/*.c game/entities/*.c game/entities/**/*.c game/*.c main.c)

# Generate names of object files
OBJS = $(SRCS:.c=.o)

# Name of executable
EXEC = main

# Default recipe
all: $(EXEC)

# Recipe for building the final executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LIBRARY_PATHS) -o $@

# Recipe for building object files
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
