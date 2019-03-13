OBJ = obj/Debug/

bin/Debug/string: $(OBJ)main.o $(OBJ)src/scalarFunction.o
	g++ $(OBJ)main.o $(OBJ)src/scalarFunction.o -lboost_program_options -o bin/Debug/string
$(OBJ)main.o: main.cpp
	g++ -c main.cpp -iquote include -lboost_program_options -o $(OBJ)main.o
$(OBJ)src/scalarFunction.o: src/scalarFunction.cpp
	g++ -c src/scalarFunction.cpp -iquote include -o $(OBJ)src/scalarFunction.o
