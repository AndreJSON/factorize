.DEFAULT_GOAL := naive
CC = g++
FLAGS = -std=c++11 -Wall -Wextra
LIBS = -lgmp -lgmpxx
COMMON = main.cpp
NAIVE = naive.cpp

naive:
	$(CC) $(FLAGS) -o main.out $(COMMON) $(NAIVE) $(LIBS)
	@echo "----------DONE!----------"

clean:
	rm -f *.out *.o