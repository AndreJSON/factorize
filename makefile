.DEFAULT_GOAL := pollard2
CC = g++
FLAGS = -std=c++11 -Wall -Wextra
LIBS = -lgmp -lgmpxx
COMMON = main.cpp

naive:
	$(CC) $(FLAGS) -o main.out $(COMMON) naive.cpp $(LIBS)
	@echo "----------DONE!----------"

naive2:
	$(CC) $(FLAGS) -o main.out $(COMMON) naive2.cpp $(LIBS)
	@echo "----------DONE!----------"

naive3:
	$(CC) $(FLAGS) -o main.out $(COMMON) naive3.cpp $(LIBS)
	@echo "----------DONE!----------"

pollard:
	$(CC) $(FLAGS) -o main.out $(COMMON) pollard.cpp $(LIBS)
	@echo "----------DONE!----------"

pollard2:
	$(CC) $(FLAGS) -o main.out $(COMMON) pollard2.cpp naive3.cpp $(LIBS)
	@echo "----------DONE!----------"

clean:
	rm -f *.out *.o