.PHONY : clean

Project :Solar
	./exec/Solar

Solar : solar.o
	g++ -o Solar solar.o -lglut -lGLU -lGL
	mv *.o ./object/
	mv Solar ./exec

solar.o:
	g++ -c ./source/solar.cpp

clean:
	rm -rf ./object/*.o
	rm -rf ./exec/*

