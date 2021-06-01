myprog: binary_search.o main.o
	g++ binary_search.o main.o -o myprog
complex.o: binary_search.o complex.h
	g++ -c binary_search.o
main.o: main.cpp 
	g++ -c main.cpp
clean:
	del *.o
