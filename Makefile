TARGET = lzw_compression
OBJS = lzw_compression.o

CFLAGS = -Wall -g -D_POSIX_C_SOURCE=199309L
CC = g++

all: clean $(TARGET)

%.o : %.cc
	$(CC) -c $(CFLAGS) $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
