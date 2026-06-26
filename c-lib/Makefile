# Makefile - C 基础函数库

CC = gcc
CFLAGS = -std=c17 -Wall
TARGET = program
SRC_DIR = src

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c
OBJS = $(SRC_DIR)/main.o $(SRC_DIR)/utils.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_DIR)/utils.o: $(SRC_DIR)/utils.c $(SRC_DIR)/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

help:
	@echo "make run - 编译并运行"
	@echo "make clean - 清理"
