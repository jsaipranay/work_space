.PHONY : clean
#Project : DexBall
#	./DexBall

DexBall : main.o menu.o
	g++ -o DexBall main.o menu.o  -lGL -lGLU -lglut 
main.o : main.cpp
	g++ -c  main.cpp
menu.o : menu.cpp
	g++ -c menu.cpp

clean:
	rm main.o DexBall menu.o
