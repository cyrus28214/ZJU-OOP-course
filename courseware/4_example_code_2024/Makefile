point_design.exe: main.o Point.o
	g++ main.o Point.o -o point_design.exe

main.o: main.cpp Point.h
	g++ -c main.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp
