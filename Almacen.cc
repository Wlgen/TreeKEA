#include "Almacen.hh"

almacen::almacen(){}

void almacen::leer_arbol(BinTree<int>& a, int marca){
	int x;
	cin >> x;
	if(x != marca){
		BinTree<int> i;
		leer_arbol(i, marca);
		BinTree<int> d;
		leer_arbol(d, marca);
		a = BinTree<int>(x, i, d);
	}
}

void almacen::inicializar_almacen(){
	int salas;
	cin >> salas;
	leer_arbol(Alm, 0);
	vector<sala> aux(salas);
	valmacen = aux;
	for(int i = 0; i < salas; ++i){
		int fil, col;
		cin >> fil >> col;
		valmacen[i] = sala(fil, col);
	}
}

int almacen::poner_items(int sala, string id, int cantidad){
	return valmacen[sala-1].poner_items(id, cantidad);
}

int almacen::quitar_items(int sala, string id, int cantidad){
	return valmacen[sala-1].quitar_items(id, cantidad);
}

int almacen::distribuir(string id, int cantidad){
	int resto = cantidad;
	distribuir2(Alm, id, cantidad, resto, valmacen);
	return resto;
}

void almacen::distribuir2(BinTree<int> a, string id, int cantidad, int& resto, vector<sala>& valmacen){
	if(not a.empty()){
		int sala = a.value();
		int sobra = valmacen[sala-1].poner_items(id, cantidad);
		resto -= (cantidad-sobra);
		if(sobra%2 == 0){
			distribuir2(a.left(), id, sobra/2, resto, valmacen);
			distribuir2(a.right(), id, sobra/2, resto, valmacen);
		}
		else{
			distribuir2(a.left(), id, (sobra+1)/2, resto, valmacen);
			distribuir2(a.right(), id, (sobra-1)/2, resto, valmacen);
		}
	}
}

void almacen::compactar(int sala){
	valmacen[sala-1].compactar();
}

void almacen::reorganizar(int sala){
	valmacen[sala-1].reorganizar();
}

void almacen::redimensionar(int sala, int f, int c, bool& error){
	valmacen[sala-1].redimensionar(f,c,error);
}

void almacen::escribir(int sala){
	valmacen[sala-1].escribir();
}

void almacen::consultar_pos(int sala, int f, int c){
	valmacen[sala-1].consultar_pos(f,c);
}
