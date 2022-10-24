CC=gcc
CFLAGS = -g -c -Wall -Werror -Wextra -Winline -Wsign-compare -Wunused-parameter -Wpointer-arith -Wshadow -Wstrict-prototypes -Wmissing-prototypes
LDFLADS= -lc
OBJS=main.o linked_list.o
TARGET=app.out

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean : 
	rm -f $(OBJS)
	rm -f $(TARGET)
