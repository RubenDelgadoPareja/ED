INCLUDE   = include
LIB       = lib
OBJ       = obj
SRC       = src
BIN       = bin
DOC       = doc
AR        = ar
CXX       = g++
CXXFLAGS  = -Wall -g -std=c++11 -c -I./$(INCLUDE) -DNDEBUG
LDFLAGS   = -L./$(LIB)
LDLIBS    = -l$(LIBNAME)
RM		  = rm -f


all: $(BIN)/usoguia $(BIN)/usodiccionario

$(BIN)/usoguia : $(OBJ)/usoguia.o
	$(CXX) -o $(BIN)/usoguia $(OBJ)/usoguia.o

$(OBJ)/usoguia.o: $(SRC)/usoguia.cpp
	$(CXX) $(CXXFLAGS) -o  $(OBJ)/usoguia.o $(SRC)/usoguia.cpp

$(BIN)/usodiccionario : $(OBJ)/usodiccionario.o
	$(CXX) -o $(BIN)/usodiccionario $(OBJ)/usodiccionario.o

$(OBJ)/usodiccionario.o: $(SRC)/usodiccionario.cpp
	$(CXX) $(CXXFLAGS) -o  $(OBJ)/usodiccionario.o $(SRC)/usodiccionario.cpp

documentacion:
	doxygen doc/doxys/Doxyfile
clean:
	-@rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	@echo "Limpiando..."

mrproper: clean
	-@rm -f $(BIN)/* $(LIB)/* $(DOC)/html/*
	@echo "Limpieza Hecha"
