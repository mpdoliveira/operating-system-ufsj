CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pthread -Iinclude

TARGET = horse_race

SRC = src/main.c src/horse.c src/terminal_control.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	del /Q $(TARGET).exe *.o 2>nul

run: $(TARGET)
	$(TARGET).exe