
#include "inventario.hh"
#include "Almacen.hh"
#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#endif

/** @mainpage 
   El programa principal, que se encuentra en el modulo program.cc, hace de menu para decidir, en cada operacion,
   cual es el modulo indicado para ejecutar esta orden.
   Teniendo en cuenta los tipos de datos que se van a necesitar para hacer la simulacion del almacen serian necesarios
   tres modulos: uno para hacer de almacen como tal, que se encargaria de la gestion de las salas, otro para las salas, asi
   poder hacer las operaciones necesarias para cada sala y tener un control de los productos en cada una de ellas de forma independiente,
   y otro modulo para hacer de inventario donde se llevaria un registro de todos los productos del almacen asi como de la cantidad que hay
   de cada uno. */

/** @file program.cc
   
   Este modulo se utiliza, principalmente, como menu para las diferentes operaciones que se pueden hacer con el almacen.
   Ademas tambien se comprueban la gran mayoria de errores de entrada y se dan las correspondientes respuestas a estos (la
   unica excepcion es el modulo inventaro, ya que este genera sus propios mensajes de error). Para seleccionar que operacion ejecutar
   se utiliza una entrada en forma de string. */

int main(){
	string opt;
	almacen A;
	inventario I;
	A.inicializar_almacen();
	while((cin >> opt) and (opt != "fin")){
		if(opt == "poner_prod"){
			string id;
			cin >> id;
			cout << opt << " " << id << endl;
			I.poner_prod(id);
		}
		else if(opt == "quitar_prod"){
			string id;
			cin >> id;
			cout << opt << " " << id << endl;
			I.quitar_prod(id);
		}
		else if(opt == "poner_items"){
			int n, cantidad;
			string id;
			cin >> n >> id >> cantidad;
			cout << opt << " " << n << " " << id << " " << cantidad << endl;
			if(not I.eesta(id)) cout << "  " << "error" << endl;
			else { 
				int sobra = A.poner_items(n, id, cantidad);
				cout << "  " << sobra << endl;
				I.poner_unidad(id, cantidad-sobra);
			}
		}
		else if(opt == "quitar_items"){
			int n, cantidad;
			string id;
			cin >> n >> id >> cantidad;
			cout << opt << " " << n << " " << id << " " << cantidad << endl;
			if(not I.eesta(id)) cout << "  " << "error" << endl;
			else{
				int sobra = A.quitar_items(n, id, cantidad);
				cout << "  " << sobra << endl;
				I.quitar_unidad(id, cantidad-sobra);
			}
		}
		else if(opt == "distribuir"){
			string id;
			int cantidad;
			cin >> id >> cantidad;
			cout << opt << " " << id << " " << cantidad << endl;
			if(not I.eesta(id)) cout << "  " << "error" << endl;
			else{ 
				int sobra = A.distribuir(id, cantidad);
				cout << "  " << sobra << endl;
				I.poner_unidad(id, cantidad-sobra);
			}
		}
		else if(opt == "compactar"){
			int n;
			cin >> n;
			cout << opt << " " << n << endl;
			A.compactar(n);
		}
		else if(opt == "reorganizar"){
				int n;
				cin >> n;
				cout << opt << " " << n << endl;
				A.reorganizar(n);
		}
		else if(opt == "redimensionar"){
				int n,f,c;
				cin >> n >> f >> c;
				cout << opt << " " << n << " " << f << " " << c << endl;
				bool error;
				A.redimensionar(n,f,c,error);
				if(error) cout << "  " << "error" << endl;
		}
		else if(opt == "inventario"){
				cout << opt << endl;
				I.consul_inventario();
		}
		else if(opt == "escribir"){
				int n;
				cin >> n;
				cout << opt << " " << n << endl;
				A.escribir(n);
		}
		else if(opt == "consultar_pos"){
				int s,f,c;
				cin >> s >> f >> c;
				cout << opt << " " << s << " " << f << " " << c << endl;
				A.consultar_pos(s,f,c);
		}
		else if(opt == "consultar_prod"){
				string id;
				cin >> id;
				cout << opt << " " << id << endl;
				if(I.eesta(id)){
					I.consultar_prod(id);
				}
				else cout << "  " << "error" << endl;
		}
	}
	cout << "fin" << endl;
}
