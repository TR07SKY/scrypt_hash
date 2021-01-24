OBJS	= crypto/scrypt.o test.o
SOURCE	= crypto/scrypt.c test.c
HEADER	=
OUT	    = test.out
FLAGS	= -g -c -Wall
LFLAGS	=

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

crypto/scrypt.o: crypto/scrypt.c
	gcc $(FLAGS) crypto/scrypt.c -o crypto/scrypt.o

test.o: test.c
	g++ $(FLAGS) test.c -o test.o

clean:
	rm -f $(OBJS) $(OUT)
