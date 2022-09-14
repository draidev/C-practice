CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lc -lpthread
OBJS=main.o
TARGET=app.out

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
