CC := gcc
FLAGS := -Wall -O2
INCLUDE := -I./include
SRC := ./src/*.c
LINK := -lSDL3 -lm

all:
	$(CC) $(SRC) $(LINK) $(FLAGS) $(INCLUDE)
