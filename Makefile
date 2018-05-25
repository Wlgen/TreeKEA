OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o inventario.o almacen.o sala.o
	g++ -o program.exe program.o inventario.o almacen.o sala.o

program.o: program.cc inventario.hh almacen.hh
	g++ -c program.cc $(OPCIONS)

inventario.o: inventario.cc inventario.hh
	g++ -c inventario.cc $(OPCIONS)

almacen.o: almacen.cc almacen.hh sala.hh
	g++ -c almacen.cc $(OPCIONS)

sala.o: sala.cc sala.hh
	g++ -c sala.cc $(OPCIONS)