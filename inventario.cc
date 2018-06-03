#include "inventario.hh"

inventario::inventario(){}

void inventario::poner_prod(string id){
	map<string, int>::iterator it = inv.find(id);
	if(it == inv.end()){
		inv.insert(make_pair(id, 0));
	}
	else cout << "  " << "error" << endl;
}

void inventario::quitar_prod(string id){
	map<string, int>::iterator it = inv.find(id);
	if(it != inv.end() and inv[id] == 0){
		inv.erase(it);
	}
	else cout << "  " << "error" << endl;
}

void inventario::poner_unidad(string id, int cantidad){
	map<string, int>::iterator it = inv.find(id);
	if(it != inv.end()){
		inv[id] += cantidad;
	}
	else cout << "  " << "error" << endl;
}

void inventario::quitar_unidad(string id, int cantidad){
	map<string, int>::iterator it = inv.find(id);
	if(it != inv.end()){
		inv[id] -= cantidad;
	}
	else cout << "  " << "error" << endl;
}

void inventario::consultar_prod(string id){
	map<string, int>::iterator it = inv.find(id);
	if(it != inv.end()){
		cout << "  " << inv[id] << endl;
	}
	else cout << "  " << "error" << endl;
}

bool inventario::eesta(string id){
	map<string, int>::iterator it = inv.find(id);
	if(it == inv.end()) return false;
	else return true;
}

void inventario::consul_inventario(){

	map<string, int>::iterator it = inv.begin();
	if(it != inv.end()){
		cout << "  " << it->first << " " << it->second << endl;
		++it;
	}
	while(it != inv.end()){
		cout << "  " << it->first << " " << it->second << endl;
		++it;
	}
}
