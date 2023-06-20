CC ?= gcc
#CFLAGS := -Wall -Werror -Wextra -pedantic
CFLAGS := -g
COBJFLAGS := $(CFLAGS) -c

OBJ_PATH := obj
SRC_PATH := src
INC_PATH := include

# Source files
SRCS := $(wildcard $(SRC_PATH)/**/*.c)
OBJS := $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRCS))

# Main target
TARGET := hsh

# Default rule
all: $(TARGET) clean

# Rule to build object files
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@

# Rule to build the executable
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

# Clean rule
clean:
	$(RM) -r $(OBJ_PATH)
