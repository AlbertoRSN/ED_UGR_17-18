SRC = src
INC = include
LIB = lib
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -c

#Rellenad el makefile para compilar el proyecto
all: $(BIN)/pruebatrad_test
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************

$(OBJ)/Frases.o : $(SRC)/Frases.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/Frases.o $(SRC)/Frases.cpp -I$(INC)

$(OBJ)/ConjuntoFrases.o : $(SRC)/ConjuntoFrases.cpp $(OBJ)/Frases.o
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/ConjuntoFrases.o $(SRC)/ConjuntoFrases.cpp -I$(INC)

$(LIB)/libconjuntofrases.a : $(OBJ)/ConjuntoFrases.o
	ar rvs $(LIB)/libconjuntofrases.a $(OBJ)/ConjuntoFrases.o $(OBJ)/Frases.o

$(BIN)/pruebatrad_test : $(OBJ)/pruebatrad_test.o $(LIB)/libconjuntofrases.a 
	$(CXX) -o $(BIN)/pruebatrad_test $(OBJ)/pruebatrad_test.o -I$(INC) -L$(LIB) -lconjuntofrases

$(OBJ)/pruebatrad_test.o : $(SRC)/pruebatrad_test.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebatrad_test.o $(SRC)/pruebatrad_test.cpp -I $(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*


