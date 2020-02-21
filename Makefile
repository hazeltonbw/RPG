a.out: main.cc map.h heroes.o game.o monster.o
	g++ main.cc -lcurl -lncurses heroes.o game.o monster.o

heroes.o: heroes.cc heroes.h
	g++ -c heroes.cc

game.o : game.cc game.h
	g++ -c game.cc

monster.o : monster.cc monster.h
	g++ -c monster.cc
clean:
	rm a.out *.o
