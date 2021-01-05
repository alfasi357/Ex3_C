CC=gcc
OBJECTS_MAINS=ex3_1.o
OBJECTS_MAIND=ex3_2.o 
OBJECTS_LIB=ex3_1.o ex3_2.o
FLAGS= -Wall -g

.PHONY= all clean

all: txtfind isort

isort: $(OBJECTS_MAINS) 
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAINS)
txtfind: $(OBJECTS_MAIND)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIND)
ex3_2.o: ex3_2.c 
	$(CC) $(FLAGS) -c ex3_2.c
ex3_1.o: ex3_1.c 
	$(CC) $(FLAGS) -c ex3_1.c
clean: 
	rm -f *.o  isort txtfind
