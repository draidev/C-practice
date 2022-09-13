CC=gcc
CFLAGS=-g -Wall
LDFLAGS=-lc
OBJS=main_malloc.o parson.o 
TARGET=main.out

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o : 
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
