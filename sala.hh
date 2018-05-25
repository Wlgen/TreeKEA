/** @file sala.hh
    @brief Especificacion de la clase sala.
*/
#ifndef _SALA_
#define _SALA_

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#endif
using namespace std;

/** @class sala
	@brief Representa una sala del almacen con una estanteria que incluye todos los productos.
	*/


class sala {
	private:
		int num_items;
		int num_items_max;
		int f, c;
		map<string, int> invsala;
		vector<string> estanteria;
		static void traspasar(vector<string>& a, vector<string>& b, int n);
		
	
	public:
		//Constructuras
		/** @brief Crea una sala con una estanteria vacia y de tamaño 0 */
		sala();
		/** @brief Crea una copia de la sala s */
		sala(const sala& s);
		/** @brief Crea una sala con una estanteria con f filas y c columnas*/
		sala(int fil, int col);
		
		//Modificadores
		
		/** @brief Aumenta la cantidad de unidades de un producto.
		  \Pre Cierto.
		  \Post Se han colocado todos los items posibles en las estanterias en los huecos
		  vacios lo antes posible y se ha modificado la cantidad de unidades del producto.
		  Si no existia se añade al registro. Se devuelve un entero que representa el numero de items
		  que no se han podido colocar. */
		int poner_items(string id, int cantidad);

		
		/** @brief Reduce la cantidad de unidades de un producto.
		  \Pre Cierto.
		  \Post Se han eliminado todos los items con ese identificador y se ha cambiado la cantidad de unidades
		  del producto, si ya no queda ninguno este se elimina del registro.Se devuelve un
		  numero entero que representa la cantidad restante de items que no se han podido
		  eliminar. En el caso de que ya no haya ningun elemento con ese identificador se devuelve -1. */
		int quitar_items(string id, int cantidad);

		
		/** @brief Compacta una sala.
		  \Pre Cierto.
		  \Post La sala se ha compactado moviendo todos los productos hacia abajo y hacia
		  la izquierda manteniendo el orden anterior de estos. */
		void compactar();

		
		/** @brief Reorganiza una sala.
		  \Pre Cierto.
		  \Post La sala se ha compactado igual que con la funcion compactar pero ahora 
		  los productos estan ordenados alfabeticamente. */
		void reorganizar();
		
		
		/** @brief Redimensiona una sala.
		  \Pre: Los productos que habian en la estanteria sin redimensionar caben en la
		  estanteria con las nuevas dimensiones.
		  Post: Los productos de la estanteria se han compactado y esta tiene las nuevas
		  dimensiones. */
		void redimensionar(int f, int c, bool& error);
		
		//Escritoras
		
		/** @brief Escribe el contenido de la sala.
		  \Pre Cierto.
		  \Post Se han escrito por el canal de salida predeterminado el contenido de la estanteria
		  de izquierda a derecha y de arriba a abajo. */
		void escribir();

		//Consultoras
		
		/** @brief Consulta el producto que se encuentra en la posicion indicada de la estanteria.
		  \Pre Cierto.
		  \Post Se ha escrito el identificador del producto que se encuentra en la posicion
		  indicada. Si no hay ningun producto se escribira NULL. */
		void consultar_pos(int i, int j);
		
		/** @brief Devuelve un entero que representa la cantidad total de elementos que puede
			almacenar la sala.*/
		int tamano();
		
		/** @brief Devuelve un entero que representa la cantidad de elementos que hay en la sala. */
		int elementos();
};
#endif
