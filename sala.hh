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

				 Aqui se incluyen todas las funciones que sirven para modificar y escribir elementos
				 en una sala.

				 Tiene operaciones de modificacion que añaden y quitan elementos de la sala y otros que cambian el orden de
				 los elementos, compactando o reordenando, y que cambian el tamaño de la estanteria, de escritura y consulta
				 que escriben el contenido de toda la estanteria de la sala o que escriben el contenido de una posicion
				 concreta del almacen.

				 Invariante:
				 num_items >= 0
				 num_items_max > 0
				 f > 0
				 c > 0
	*/
class sala {

	//Descripcion: Contiene diferentes elementos representados cada uno por un identificador.	

	private:

	/* Una sala esta formada por un vector donde se guardan todos los elementos de la estanteria, haciendo
	la funcion de esta, como si fuera una matriz, (el uso del vector es debido a que, de esta manera, se
	simplifica la implementacion de algunos algoritmos como el de compactar, reorganizar o redimensionar)
	utilizando los parametros f y c para saber exactamente las medidas de la estanteria, dos parametros mas
	para saber la cantidad de elementos que hay en la estanteria en todo momento y para saber el tamaño maximo
	de la estanteria y un diccionario para mantener un inventario sencillo de acceder a la hora de utilzar
	la operacion escribir. */

	/** @brief Parametro encargado de mantener el valor igual a la cantidad de elementos de la estanteria */
		int num_items;
		
		/** @brief Parametro que indica la cantidad maxima de elementos que se pueden almacenar en la estanteria */
		int num_items_max;

		/** @brief f indica la cantidad de filas de la estanteria y c la cantidad de columnas. */
		int f, c;

		/** @brief Diccionario que sirve como inventario de los productos que hay en la sala. */
		map<string, int> invsala;

		/** @brief Este vector es la estanteria como tal. */
		vector<string> estanteria;

		/** @brief Copia los elementos de un vector a otro, manteniendo el orden inicial pero
		  sin huecos (un hueco es una posicion en la que haya "{}") entre los elementos en el vector de llegada.
			\pre a.size() >= n
			\post Los elementos que habian en el vector a ahora se encuentran, tambien, en el vector b sin huecos
			entre ellos.
			\coste Lineal respecto a la cantidad de elementos n. */
		static void traspasar(vector<string>& a, vector<string>& b, int n);
		
	
	public:
		//Constructuras

		/** @brief Crea una sala con una estanteria vacia y de tamaño 0.
		 *  \pre cierto
		 * 	\post El resultado es una sala con los parametros vacios.
		 * 	\coste Constante
		 */
		sala();
	
		/** @brief Crea una sala con una estanteria con f filas y c columnas.
		    \pre cierto
		   	\post El resultado es una sala vacia de tamaño igual al indicado por el
		   	el numero de filas y columnas introducido.
		    \coste Constante
		*/
		sala(int fil, int col);
		
		//Modificadores
		
		/** @brief Aumenta la cantidad de unidades de un producto.
		  \pre 0 <= cantidad.
		  \post Se han colocado todos los items posibles en las estanterias en los huecos
		  vacios lo antes posible y se ha modificado la cantidad de unidades del producto.
		  Si no existia se añade al registro. Se devuelve un entero que representa el numero de items
		  que no se han podido colocar.
			\coste Linieal respecto a la cantidad de elementos totales que pueda almacenar la sala.
			 */
		int poner_items(string id, int cantidad);

		
		/** @brief Reduce la cantidad de unidades de un producto.
		  \pre 0 <= cantidad.
		  \post Se han eliminado todos los items con ese identificador y se ha cambiado la cantidad de unidades
		  del producto, si ya no queda ninguno este se elimina del registro.Se devuelve un
		  numero entero que representa la cantidad restante de items que no se han podido
		  eliminar.
			\coste Lineal respecto a la cantidad de elementos que pueda almacenar la sala. */
		int quitar_items(string id, int cantidad);

		
		/** @brief Compacta una sala.
		  \pre Cierto.
		  \post La sala se ha compactado moviendo todos los productos hacia abajo y hacia
		  la izquierda manteniendo el orden anterior de estos.
			\coste Lineal respecto al tamaño de la sala. */
		void compactar();

		
		/** @brief Reorganiza una sala.
		  \pre cierto.
		  \post La sala se ha compactado igual que con la funcion compactar pero ahora 
		  los productos estan ordenados alfabeticamente. 
			\coste n*log(n) respecto el tamaño de la estanteria. */
		void reorganizar();
		
		
		/** @brief Redimensiona una sala.
		  \pre (f*c) >= cantidad de elementos de la sala.
		  \post Los productos de la estanteria se han compactado y esta tiene las nuevas
		  dimensiones.
			\coste Logaritmico con respecto al tamaño de la nueva estanteria */
		void redimensionar(int f, int c, bool& error);
		
		//Escritoras
		
		/** @brief Escribe el contenido de la sala.
		  \pre Cierto.
		  \post Se han escrito por el canal de salida predeterminado el contenido de la estanteria
		  de izquierda a derecha y de arriba a abajo.
			\coste Lineal respecto al tamaño de la estanteria */
		void escribir();

		//Consultoras
		
		/** @brief Consulta el producto que se encuentra en la posicion indicada de la estanteria.
		  \pre La posicion a consultar existe en la estanteria.
		  \Post Se ha escrito el identificador del producto que se encuentra en la posicion
		  indicada. Si no hay ningun producto se escribira NULL.
			\coste Constante. */
		void consultar_pos(int i, int j);
		
		/** @brief Devuelve un entero que representa la cantidad total de elementos que puede
			almacenar la sala.
			\pre cierto
			\post La funcion devuelve el tamaño de la estanteria.
			\coste Constante.*/
		int tamano();
		
		/** @brief Devuelve un entero que representa la cantidad de elementos que hay en la sala.
		   \pre cierto
			 \post Se ha devuelto la cantidad de elementos que hay en la estanteria en ese momento.
			 \coste Constante.*/
		int elementos();
};
#endif
