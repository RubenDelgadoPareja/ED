negativo: negativo.o imagenES.o imagen.o
	g++ -g -o negativo negativo.o imagenES.o imagen.o

imagenES.o: imagenES.cpp imagenES.h
	g++ -g -c -o imagenES.o -I. imagenES.cpp

negativo.o: negativo.cpp
	g++ -g -c -o negativo.o -I. negativo.cpp

imagen.o: imagen.cpp imagen.h
	g++ -g -c -o imagen.o -I. imagen.cpp
