# Makefile - C 文件操作演示

CC = gcc
CFLAGS = -std=c17 -Wall -g
TARGET = program
SRC_DIR = src

all: $(TARGET)

$(TARGET): $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGET) test.txt data.bin copy1.txt copy2.txt

run: $(TARGET)
	./$(TARGET)

help:
	@echo "make run  - 编译并运行"
	@echo "make clean - 清理"
