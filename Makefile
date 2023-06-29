CC ?= gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=c90

ifdef DEBUG
	CFLAGS := $(CFLAGS) -g
endif

OBJ_PATH := $(or $(obj_path), obj)
INC_PATH := $(or $(headers), include)
SRC_PATH := $(or $(src_path), src)

SRC_FILES := $(shell find $(SRC_PATH) -type f -name '*.c')
OBJ_FILES := $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o,$(SRC_FILES))

TARGET := hsh

all: $(TARGET) clean

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c -I$(INC_PATH) -o $@ $<

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_PATH)