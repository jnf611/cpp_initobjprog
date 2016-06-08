CC = g++
CPP_FLAGS = -g -std=c++11 -Wall -Wextra
# add -Wpedantic ?

all: complexe

OBJ_COMPLEXE = Complexe.o s03-e10-complexe.o

complexe: complexe-object
	$(CC) $(CPP_FLAGS) -o s03-e10-complexe $(OBJ_COMPLEXE)

complexe-object: $(OBJ_COMPLEXE)

Complexe.o: Complexe.cpp
	$(CC) $(CPP_FLAGS) -c Complexe.cpp

s03-e10-complexe.o: s03-e10-complexe.cpp
	$(CC) $(CPP_FLAGS) -c s03-e10-complexe.cpp
	
clean:
	../clean.sh
