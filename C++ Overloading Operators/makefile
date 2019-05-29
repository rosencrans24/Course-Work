all: lab7

lab7: Lab7.o Term.o 
	g++ Lab7.o Term.o -o lab7
lab7.o: Lab7.cpp Term.cpp
	g++ -c Lab7.cpp
Term.o: Term.cpp Term.h
	g++ -c Term.cpp
clean:
	rm -rf *.o