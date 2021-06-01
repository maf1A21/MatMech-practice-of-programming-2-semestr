myProg: main.o library.o
	g++ main.o library.o -o myProg
library.o: library.cpp library.h
	g++ -c library.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f myProg *.o
