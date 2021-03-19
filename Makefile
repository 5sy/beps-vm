TARGET	:= beps-vm

CC		:= gcc
CFLAGS	:= -Wall -std=c99 -O2

SRC		:= $(shell find src -type f -name "*.c")
OBJ		:= $(patsubst %.c,%.o,$(SRC))
.PHONY:	all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJ)
