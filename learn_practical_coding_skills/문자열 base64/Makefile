CC=gcc
CFLAGS=-g -Wall
TARGET=b64_main.out
OBJS=b64_main.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
