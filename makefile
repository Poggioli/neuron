#makefile

OBJS	= mergesortMultiThread.o
SOURCE	= mergesortMultiThread.c
HEADER	= 
OUT	= mergesortMultiThread
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = -lpthread

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

mergesortMultiThread.o: mergesortMultiThread.c
	$(CC) $(FLAGS) mergesortMultiThread.c 


clean:
	rm -f $(OBJS) $(OUT)