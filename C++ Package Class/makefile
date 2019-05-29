all: lab8

lab8: Lab8.o Package.o TwoDayPackage.o
	g++ Lab8.o Package.o TwoDayPackage.o -o lab8
Lab8.o: Lab8.cpp Package.cpp TwoDayPackage.cpp
	g++ -c Lab8.cpp
Package.o: Package.cpp Package.h
	g++ -c Package.cpp
TwoDayPackage: TwoDayPackage.cpp TwoDayPackage.cpp
	g++ -c TwoDayPackage.cpp
