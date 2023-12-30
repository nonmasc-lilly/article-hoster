all: main.c utils/*.c
	gcc main.c utils/*.c -o main -std=c89 -Wpedantic
