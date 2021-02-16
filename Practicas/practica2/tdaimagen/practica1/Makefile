main: main.o imagenES.o imagen.o
	g++ -g -o main main.o imagenES.o imagen.o

imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp

main.o: main.cpp
	g++ -g -c -o main.o -I. main.cpp

imagen.o: imagen.cpp imagen.h
	g++ -g -c -o imagen.o -I. imagen.cpp
