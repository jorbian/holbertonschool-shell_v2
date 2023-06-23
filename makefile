#TEMPOARY MAKEFILE FOR EXPERIMENT

CC ?= gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
COBJFLAGS := $(CFLAGS) -c

TARGET := hsh

SRC_FILES=$(wildcard *.c)
OBJ_FILES=$(SRC_FILES:.c=.o)

TARGET := hsh

all: $(TARGET) clean

%.o: %.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_FILES)
