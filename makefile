OBJS	= utils/util.o crypto/scrypt.o test.o
SOURCE	= utils/util.cpp crypto/scrypt.c test.cpp
HEADER	=
OUT	    = test.out
CC	    = g++
FLAGS	= -g -c -Wall
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

utils/util.o: utils/util.cpp
	$(CC) $(FLAGS) utils/util.cpp -o utils/util.o

crypto/scrypt.o: crypto/scrypt.c
	gcc $(FLAGS) crypto/scrypt.c -o crypto/scrypt.o

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp -o test.o

clean:
	rm -f $(OBJS) $(OUT)
