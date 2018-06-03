/** @file almacen.hh
	@brief Especificacion de la clase almacen
	*/
	
#ifndef _ALMACEN_
#define _ALMACEN_

#include "sala.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#endif

/** @class almacen
	@brief Representa el almacen como tal, imitando la estructura y sus funciones.

	Hay operaciones modificadoras, que inicializan un almacen, para añadir y quitar elementos de una sala especifica,
	para distribuirlos por todo el almacen, para compactar, reorganizar o redimensionar una sala especifica, y consultoras,
	como escribir, que escribe una sala especifica, o consultar_pos, que escribe el elemento que se encuetra en una
	posicion concreta en una sala concreta.
	*/

class almacen{

	//Descripcion: Hace las veces de almacen, guardando la estructura de este y gestiona las diferentes salas.

	private:
	/* Para la estructura del almacen se utiliza un arbol binario, aunque para una mejor implementacion y mayor
	eficiencia las salas se almacenan en un vector. */

	/** @brief Arbol binario para almacenar el orden de las salas del almacen.*/
	BinTree<int> Alm;

	/** @brief Vector donde se almacenan las salas. */
	vector<sala> valmacen;

	/** @brief Funcion que lee y genera un arbol a partir de una secuencia de numeros en preorden.
	   \pre cierto
		 \post El resultado es un arbol generado a partir de una secuencia introducida en preorden.
		 \coste Lineal respecto a la cantidad de nodos del arbol. */
	static void leer_arbol(BinTree<int>& a, int marca);

	/** @brief Immersion de la funcion distribuir para distribuir productos por el almacen.
	   \pre cantidad >= 0, resto >= 0.
		 \post La cantidad de productos especificada en cantidad ha sido distribuida por el almacen desde
		 la sala a.value() hasta abajo, resto = cantidad - cantidad distribuida.
		 \coste Lineal respecto a la cantidad de salas de a y la cantidad de elementos total que pueda almacenar
		 cada sala. */
	static void distribuir2(BinTree<int> a, string id, int cantidad, int& resto, vector<sala>& valmacen);	
	
	public:
	
	//Constructoras
	
	/** @brief Crea un alamcen vacio y sin salas */
	almacen();
	
	//Modificadoras
	
	/** @brief Inicializa el almacen con la organizacion de salas y tamaño de estanterias que se le introduce.
	  \pre El almacen es vacio y sin salas.
	  \post El almacen tiene las salas y la organicacion de salas que se le
	   ha introducido por el canal de entrada, al igual que el tamaño de las
	   estanterias de las salas, el cual ha sido introducido, tambien, por el
	   canal de entrada, y estas se han inicializado completamente vacias.
		 \coste 2n respecto a la cantidad de salas*/
	void inicializar_almacen();
	    
	
	/** @brief Se colocan una cantidad de unidades de un producto en una sala del almacen.
	  \pre El producto se encuentra en el sistema.
	  \post Se han colocado tantas unidades como cabian en la sala llenando primero
	  los huecos vacios que se encuentren antes y se devuelve un entero indicando 
	  la cantidad de unidades que no se han podido colocar.
		\coste Lineal respecto a la cantidad total de productos que pueda amacenar la sala. */
	int poner_items(int sala, string id, int cantidad);
	
	
	/** @brief Se eliminan una cantidad de unidades de un producto de una sala del almacen.
	  \pre El producto se encuentra en el sistema.
	  \post Se han eliminado tantas unidades como se han podido en el sistema
	  empezando por las que se encuentran antes y se devuelve un entero que
	  representa la cantidad de items que no se han podido eliminar.
		\coste Lineal respecto a la cantidad de elementos que pueda almacenar la sala. */ 
	int quitar_items(int sala, string id, int cantidad);
	
	
	/** @brief Se distribuyen una cantidad de unidades de un producto por todo el almacen
	  \pre El producto se encuentra en el sistema.
	  \post El producto se ha distribuido de manera que, si no caben todos en la primera sala,
	  se distribuyen una mitad en la sala de la derecha y otra mitad en la sala de la izquierda,
	  dentro de la sala se utiliza el mismo criterio de distribucion que en las funciones anteriores.
	  Se devuelve un entero que representa la cantidad de productos que no se han podido
	  distribuir en el almacen.
		\coste Lineal respecto a la cantidad de salas de a y la cantidad de elementos total que pueda almacenar
		 cada sala. */
	int distribuir(string id, int cantidad);
	 
	
	/** @brief Se compacta la estanteria de la sala indicada.
	  \pre cierto
	  \post La estanteria de la sala se ha compactado, manteniendo el orden de los elementos, moviendolos todos
	  hacia la izquierda y hacia abajo.
		\coste Lineal respecto al tamaño de la sala. */
	void compactar(int sala);
	 
	
	/** @brief Se reorganiza la estanteria de la sala indicada.
	  \pre cierto
	  \post La estanteria de la sala se ha compactado igual que con la funcion compactar,
	  pero ahora los elementos estan ordenados alfabeticamente.
		\coste n*log(n) respecto el tamaño de la estanteria. */
	void reorganizar(int sala);
	 
	
	/** @brief Se redimensiona la estanteria de la sala indicada.
	  \pre cierto
	  \post La sala se ha compactado y tiene las nuevas dimensiones.
		\cost Logaritmico con respecto al tamaño de la nueva estanteria. */
	void redimensionar(int sala, int f, int c, bool& error);
	 
	//Escritoras
	
	/** @brief Se escriben los productos que contiene la sala indicada.
	  \pre cierto
	  \post Se ha escrito por el canal de salida los productos de la sala de izquierda a derecha
	  y de arriba a abajo. Tambien se escribe la cantidad de unidades de cada producto escribiendo
	  primero si identificador de producto y luego la cantidad. Todo esto por orden alfabetico de identificador.
		\coste Lineal respecto al tamaño de la estanteria. */
	void escribir(int sala);
	
	//Consultoras
	
	/** @brief Se escribe el producto que se encuentra en la posicion de la estanteria de la sala indicada.
	  \pre cierto
	  \post Se ha indicado por el canal de salida predeterminado el producto que se encuentra en la 
	  sala, la fila y la columna indicados. Si no hay ningun prodcto en la posicion indicada se escribe NULL.
		\coste Constante. */
	void consultar_pos(int sala, int f, int c);

 };
#endif
