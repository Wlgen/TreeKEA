#include "sala.hh"


sala::sala(){
	num_items = 0;
	num_items_max = 0;
	f = c = 0;
}

sala::sala(int fil, int col){
	int size = fil*col;
	vector<string> aux(size, "{}");
	estanteria = aux;
	f = fil;
	c = col;
	num_items_max = (size);
	num_items = 0;
}

int sala::poner_items(string id, int cantidad){
	int cant = cantidad;
	if(num_items == num_items_max or cantidad == 0){
		return cant;
	}
	else{
		for(int i = 0; i < f and cant != 0; ++i){
			for(int j = 0; j < c and cant != 0; ++j){
				if(estanteria[(i*c)+j] == "{}"){
				estanteria[(i*c)+j] = id;
				--cant;
				}
			}
		}
		if(invsala.find(id) == invsala.end()){
			invsala.insert(make_pair(id, cantidad - cant));
		}
		else invsala[id] += (cantidad-cant);
		num_items += (cantidad - cant);
		return cant;
	}
}

int sala::quitar_items(string id, int cantidad){
	int cant = cantidad;
	for(int i = 0; i < f and cant != 0; ++i){
		for(int j = 0; j < c and cant != 0; ++j){
			if(estanteria[(i*c)+j] == id){
			estanteria[(i*c)+j] = "{}";
			--cant;
			}
		}
	}
	invsala[id] -= (cantidad - cant);
	if(invsala[id] == 0) invsala.erase(id);
	num_items -= (cantidad - cant);
	return cant;
}

void sala::compactar(){
	vector<string> aux(num_items_max, "{}");
	traspasar(aux, estanteria, num_items_max);
	estanteria = aux;
}

void sala::reorganizar(){
	sort (estanteria.begin(), estanteria.end());
}

void sala::redimensionar(int fil, int col, bool& error){
	if((fil*col) >= num_items){
		vector<string> aux((fil*col), "{}");
		traspasar(aux, estanteria, num_items_max);
		f = fil;
		c = col;
		estanteria = aux;
		num_items_max = (f*c);
		error = false;
	}
	else error = true;
}

void sala::escribir(){
	for(int i = f-1; i >= 0; --i){
		cout << " ";
		for(int j = 0; j < c; ++j){
			if(estanteria[(i*c)+j] == "{}") cout << " "<< "NULL";
			else cout << " " << estanteria[(i*c)+j];
		}
		cout << endl;
	}
	cout << "  " << num_items << endl;
	if(not invsala.empty()){
		for(map<string, int>::iterator it = invsala.begin(); it != invsala.end(); ++it){
			cout << "  " << it->first << " " << it->second << endl;
		}
	}
}

void sala::consultar_pos(int i, int j){
	if(i > f or j > c) cout << "  " << "error" << endl;
	else{
		if(estanteria[(f-i)*c+(j-1)] == "{}") cout << "  " << "NULL" << endl;
		else cout << "  " << estanteria[(f-i)*c+(j-1)] << endl;
	}
}

int sala::tamano(){
	return num_items_max;
}

int sala::elementos(){
	return num_items;
}

void sala::traspasar(vector<string>& a, vector<string>& b, int n){
	int j = 0;
	for(int i = 0; i < n; ++i){
		if(b[i] != "{}"){
			a[j] = b[i];
			++j;
		}
	}
}