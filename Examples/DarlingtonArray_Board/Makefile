MAIN = main.cpp
OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
IDIR = -I/usr/include -I/usr/local/include
LDIR = -L/usr/lib -L/usr/local/lib
LIBS = -lMagzorI2C -lwiringPi
DEFINES = -DRASPBERRYPI

all: $(OBJS)
	$(CC) $(LFLAGS) $(LDIR) $(LIBS) $(OBJS) -o a.out

main.o: $(MAIN)
	$(CC) $(CFLAGS) $(IDIR) $(MAIN) $(DEFINES) -o main.o

clean:
	\rm *.o *~ *.gch a.out 2>/dev/null || true
