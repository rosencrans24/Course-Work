all: calendar

calendar: Calendar.o Date.o Time.o 
	g++ Calendar.o Date.o Time.o -o calendar
Calendar.o: Calendar.cpp Date.h Time.h
	g++ -c Calendar.cpp
Date.o: Date.cpp Date.h
	g++ -c Date.cpp
Time.o: Time.cpp Time.h
	g++ -c Time.cpp
clean:
	rm -rf *.o