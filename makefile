RM = rm -f 
CC = g++
CFLAGS = -g -Wall -Wextra

default: imagestacker


imagestacker: stacker.o main.o
        $(CC) $(CFLAGS) -o imagestacker stacker.o main.o


stacker.o: stacker.cpp stacker.h
        $(CC) $(CFLAGS) -c stacker.cpp


# Then, the rule to create main.o

main.o: main.cpp stacker.h
        $(CC) $(CFLAGS) -c main.cpp

# Now the logic to clean things up! (invoked with 'make clean')

clean:
        $(RM) imagestacker *.o *~