CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g3
CPPFLAGS = -I ./src/include/
LDFLAGS = -lSDL -lSDL_image

SRC = src/game.c src/draw.c src/update.c
OBJ = $(SRC:.c=.o)
TARGET = dougenics

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean :
	$(RM) $(TARGET) $(OBJ)
