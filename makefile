numerology : main.o list.o
	g++ main.o list.o -o numerology

main.o : main.h list.h header.h
	g++ -c $*.cpp

list.o : list.h header.h
	g++ -c $*.cpp

run : numerology
	./numerology

clean :
	rm *.o *.txt numerology