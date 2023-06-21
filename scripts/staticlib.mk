# Serves as a generic file to build contents of folder as static library
OUTPUT_FILE := $(out_file)
HEADER_PATH := $(headers)
#DEFAULT_HEADER_PATH := $(shell ./find_folder_path.sh include)
DEFAULT_HEADER_PATH := ../../include

CC ?= gcc
CFLAGS := -Wall -Werror -Wextra -pedantic
COBJFLAGS := $(CFLAGS) -c
ARFLAGS = rsv

INC_PATH := $(or $(HEADER_PATH), $(DEFAULT_HEADER_PATH))
TARGET := $(or $(OUTPUT_FILE), $(addsuffix .a, $(notdir $(shell pwd))))
SRCS := $(wildcard *.c)
OBJS := $(addsuffix .o, $(basename $(SRCS)))

default: $(TARGET) clean

$(TARGET): $(OBJS)
	ar $(ARFLAGS) $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(COBJFLAGS) -I$(INC_PATH) -o $@ $<

.PHONY: clean
clean:
	@rm -f $(OBJS)
