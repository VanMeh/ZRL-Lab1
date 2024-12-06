OBJS	= output/main.o output/lab1.o
SOURCE	= main.c lab1.c
HEADER	= lab1.h
OUT	= output/lab1
CFLAGS	= -g -c 
CC	= gcc
ARG = ""

all:	output/lab1

output/lab1: $(OBJS)
	$(CC) -o $@ $^

output/%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ $< 

clean:
	rm -f $(OBJS) $(OUT)

run: output/lab1
	make clean
	make
	./output/lab1 $(ARG)