SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

# ************ Compilación de módulos ************:
all: $(BIN)/usopilas_max
	
$(BIN)/usopilas_max: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h
	g++ -std=c++11 -g -w $(SRC)/usopilas_max.cpp $(SRC)/pila_max.cpp -I$(INC) -o $(BIN)/usopilas_max 


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/*

mrproper : clean
	-rm $(BIN)/* doc/html/*
