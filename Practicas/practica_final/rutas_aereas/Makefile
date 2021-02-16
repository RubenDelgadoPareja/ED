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


all: $(BIN)/rutas_aereas

$(BIN)/rutas_aereas : $(SRC)/rutas_aereas.cpp $(INCLUDE)/imagen.h   $(INCLUDE)/imagenES.h $(INCLUDE)/almacen_rutas.h $(INCLUDE)/Paises.h
	g++ -std=c++11 -g -w $(SRC)/rutas_aereas.cpp $(SRC)/imagen.cpp $(SRC)/imagenES.cpp -I$(INCLUDE) -o $(BIN)/rutas_aereas

#$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp 
	# $(CXX) $(CXXFLAGS) -I$(INCLUDE) -o  $(OBJ)/rutas_aereas.o $(SRC)/rutas_aereas.cpp $(SRC)/imagen.cpp $(SRC)/imagenES.cpp 

#$(OBJ)/imagen.o: $(SRC)/imagen.cpp
	#$(CXX) $(CXXFLAGS) -o  $(OBJ)/imagen.o $(SRC)/imagen.cpp

#$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp
	#$(CXX) $(CXXFLAGS) -o  $(OBJ)/imagenES.o $(SRC)/imagenES.cpp


documentacion:
	doxygen doc/doxys/Doxyfile
clean:
	-@rm -f $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~
	@echo "Limpiando..."

mrproper: clean
	-@rm -f $(BIN)/* $(LIB)/* $(DOC)/html/*
	@echo "Limpieza Hecha"


#Linea de argumentos del ejecutable
#./bin/rutas_aereas /home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/paises.txt /home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/imagenes/mapas/mapa1.ppm /home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/imagenes/banderas/ a/home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/almacen_rutas.txt 
#  /home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/imagenes/aviones/avion1.ppm  /home/ruben/ED/Practicas/practica_final/rutas_aereas/datos/imagenes/aviones/mascara_avion1.pgm