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
	*/

class almacen{
	private:
	BinTree<int> Alm;
	vector<sala> valmacen;
	static void leer_arbol(BinTree<int>& a, int marca);
	static void distribuir2(BinTree<int> a, string id, int cantidad, int& resto, vector<sala>& valmacen);	
	
	public:
	
	//Constructoras
	
	/** @brief Crea un alamcen vacio y sin salas */
	almacen();
	
	//Modificadoras
	
	/** @brief Inicializa el almacen con la organizacion de salas y tamaño de estanterias que se le introduce.
	  \Pre El almacen es vacio y sin salas.
	  \Post El almacen tiene las salas y la organicacion de salas que se le
	   ha introducido por el canal de entrada, al igual que el tamaño de las
	   estanterias de las salas, el cual ha sido introducido, tambien, por el
	   canal de entrada */
	void inicializar_almacen();
	    
	
	/** @brief Se colocan una cantidad de unidades de un producto en una sala del almacen.
	  \Pre El producto se encuentra en el sistema.
	  \Post Se han colocado tantas unidades como cabian en la sala llenando primero
	  los huecos vacios que se encuentren antes y se devuelve un entero indicando 
	  la cantidad de unidades que no se han podido colocar. */
	int poner_items(int sala, string id, int cantidad);
	
	
	/** @brief Se eliminan una cantidad de unidades de un producto de una sala del almacen.
	  \Pre El producto se encuentra en el sistema.
	  \Post Se han eliminado tantas unidades como se han podido en el sistema
	  empezando por las que se encuentran antes y se devuelve un entero que
	  representa la cantidad de items que no se han podido eliminar. */ 
	int quitar_items(int sala, string id, int cantidad);
	
	
	/** @brief Se distribuyen una cantidad de unidades de un producto por todo el almacen
	  \Pre El producto se encuentra en el sistema.
	  \Post El producto se ha distribuido de manera que, si no caben todos en la primera sala,
	  se distribuyen una mitad en la sala de la derecha y otra mitad en la sala de la izquierda,
	  dentro de la sala se utiliza el mismo criterio de distribucion que en las funciones anteriores.
	  Se devuelve un entero que representa la cantidad de productos que no se han podido
	  distribuir en el almacen. */
	int distribuir(string id, int cantidad);
	 
	
	/** @brief Se compacta la estanteria de la sala indicada.
	  \Pre Cierto.
	  \Post La estanteria de la sala se ha compactado, manteniendo el orden de los elementos, moviendolos todos
	  hacia la izquierda y hacia abajo. */
	void compactar(int sala);
	 
	
	/** @brief Se reorganiza la estanteria de la sala indicada.
	  \Pre Cierto.
	  \Post La estanteria de la sala se ha compactado igual que con la funcion compactar,
	  pero ahora los elementos estan ordenados alfabeticamente */
	void reorganizar(int sala);
	 
	
	/** @brief Se redimensiona la estanteria de la sala indicada.
	  \Pre Cierto.
	  \Post La sala se ha compactado y tiene las nuevas dimensiones. */
	void redimensionar(int sala, int f, int c, bool& error);
	 
	//Escritoras
	
	/** @brief Se escriben los productos que contiene la sala indicada.
	  \Pre Cert.
	  \Post Se ha escrito por el canal de salida los productos de la sala de izquierda a derecha
	  y de arriba a abajo. Tambien se escribe la cantidad de unidades de cada producto escribiendo
	  primero si identificador de producto y luego la cantidad. Todo esto por orden alfabetico de identificador. */
	void escribir(int sala);
	
	//Consultoras
	
	/** @brief Se escribe el producto que se encuentra en la posicion de la estanteria de la sala indicada.
	  \Pre Cierto.
	  \Post Se ha indicado por el canal de salida predeterminado el producto que se encuentra en la 
	  sala, la fila y la columna indicados. Si no hay ningun prodcto en la posicion indicada se escribe NULL. */
	void consultar_pos(int sala, int f, int c);

 };
#endif
