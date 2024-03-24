# Target Name:
TARGET = CTemplate

# Compiler Setup:
CC = gcc
CFLAGS = -Wall
BUILD ?= DEBUG

# SDL2 Setup:
SDL2_CONFIG = sdl2-config
SDL2_LIBRARY = $(shell $(SDL2_CONFIG) --libs)
SDL2_CFLAGS = $(shell $(SDL2_CONFIG) --cflags)
SDL2_LINKING = -lSDL2_image

# Directory Setup:
OBJ_DIR = obj
SRC_DIR = src

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

ifeq ($(BUILD), RELEASE)
	CFLAGS += -O2 -s
endif

ifeq ($(BUILD), DEBUG)
	CFLAGS += -g -DDEBUG -O0
endif

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(SDL2_LIBRARY) $(SDL2_LINKING)

$(OBJ): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) $(SDL2_CFLAGS)

clean:
	rm $(TARGET)
	rm $(OBJ_DIR)/*.o

.phony: clean
