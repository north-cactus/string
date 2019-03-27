OBJ = obj/Debug/

.PHONY: clean

bin/Debug/string: $(OBJ)main.o $(OBJ)src/scalar2DFunction.o $(OBJ)src/EulerString.o $(OBJ)src/phase.o $(OBJ)src/trigonometricMonom.o
	g++ $(OBJ)main.o $(OBJ)src/scalar2DFunction.o $(OBJ)src/EulerString.o $(OBJ)src/phase.o $(OBJ)src/trigonometricMonom.o -lboost_program_options -o bin/Debug/string
$(OBJ)%.o: %.cpp
	g++ -c $^ -iquote include -lboost_program_options -o $@
clean:
	rm $(OBJ)main.o $(OBJ)src/*.o
