OBJ = obj/Debug/

bin/Debug/string: $(OBJ)main.o $(OBJ)src/scalar2DFunction.o
	g++ $(OBJ)main.o $(OBJ)src/scalar2DFunction.o -lboost_program_options -o bin/Debug/string
$(OBJ)main.o: main.cpp
	g++ -c main.cpp -iquote include -lboost_program_options -o $(OBJ)main.o
$(OBJ)src/scalar2DFunction.o: src/scalar2DFunction.cpp
	g++ -c src/scalar2DFunction.cpp -iquote include -o $(OBJ)src/scalar2DFunction.o
