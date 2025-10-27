CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
OBJ = main.o platform.o post.o comment.o reply.o
TARGET = social_media_app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c platform.h
	$(CC) $(CFLAGS) -c main.c

platform.o: platform.c platform.h post.h comment.h reply.h
	$(CC) $(CFLAGS) -c platform.c

post.o: post.c post.h comment.h
	$(CC) $(CFLAGS) -c post.c

comment.o: comment.c comment.h reply.h
	$(CC) $(CFLAGS) -c comment.c

reply.o: reply.c reply.h
	$(CC) $(CFLAGS) -c reply.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
