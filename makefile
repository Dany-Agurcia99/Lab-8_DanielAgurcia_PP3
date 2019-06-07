run: Main.o Pieza.o Peon.o Alfil.o Caballo.o Torre.o Reina.o Rey.o Partida.o 
	g++ Main.o Pieza.o Peon.o Alfil.o Caballo.o Torre.o Reina.o Rey.o Partida.o -o run
Pieza.o: Pieza.cpp Peon.cpp Alfil.cpp Caballo.cpp Torre.cpp Reina.cpp Rey.cpp
	g++ -c Pieza.cpp Peon.cpp Alfil.cpp Caballo.cpp Torre.cpp Reina.cpp Rey.cpp
Partida.o: Partida.cpp
	g++ -c Partida.cpp
Main.o: Main.cpp
	g++ -c Main.cpp