myProg: main.o class_A.o
	g++ main.o class_A.o -o myProg
class_A.o: class_A.cpp 
	g++ -c class_A.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f myProg *.o
