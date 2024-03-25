output: Matrix.o
	g++ Matrix.o -o output

Matrix.o: Matrix.cpp
	g++ -c Matrix.cpp

clean:
	rm *.o *.exe