/** @file inventario.hh
	@brief Especificacion de la clase inventario. */
#ifndef _INVENTARIO_
#define _INVENTARIO_

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#include <iostream>
#endif
using namespace std;

/** @class inventario
	@brief Representacion del inventario de la tienda en la que estan todos
	los productos y la cantidad de unidades que hay de cada uno.

	Se pueden encontrar operaciones de modificacion, que añaden o quitan producto al sistema, y que añaden o quitan
	una cantidad de elementos de cada producto, y de consulta, que escriben la cantidad de elementos que hay de un producto,
	que devuelvan un booleano dependiendo de si el producto a consultar se encuentra en el sistema y que escriben todo el inventario
	disponible en el sistema en ese momento.

	Invariante:
		La cantidad de elementos de un producto siempre sera >= 0.
	*/

class inventario{
	
	//Descripcion: Inventario que guarda un registro de los productos disponibles en el almacen y de su stock en todo momento.

	private:

	/* Para poder mantener un registro de un almacen se utiliza un diccionario que utilice los identificadores
	de los productos como indices de los elementos y un entero como parametro para representar el stock disponible
	en ese momento. */

	/** @brief Diccionario en el que se guardan todos los productos junto con su cantidad de elementos de ese producto. */
	map<string, int> inv;
	
	public:
	//Constructoras
	
	/** @brief Se crea una variable inventario con ningun producto dado de alta. */
	inventario();
	
	//Modificadoras
	
	/** @brief Se añade un nuevo producto al sistema.  
	  \pre El producto no existia en el sistema.
	  \post El producto se ha dado de alta en le sistema con 0 unidades.
		\coste Doble logaritmico respecto la cantidad de productos que haya en el sistema. */
	void poner_prod(string id);
	 
	
	/** @brief Se elimina un producto existente del sistema.
	  \pre El producto existe en el sistema y tiene 0 unidades.
	  \post El producto se ha eliminado del sistema.
		\coste Logaritmico respecto la cantidad de productos que haya en el sistema. */
	void quitar_prod(string id);
	 
	
	/** @brief Se suma a las unidades existentes la cantidad indicada.
	  \Pre Cierto.
	  \Post Se ha sumado la cantidad indicada de unidades a la cantidad que habia del producto
	  indicado.
		\coste Logaritmico respecto la cantidad de productos que haya en el sistema. */
	void poner_unidad(string id, int cantidad);
	
	
	/** @brief Se quitan tantas unidades del producto como se indican.
	  \pre cantidad >= 0 and cantidad <= inv[id]
	  \post Se han eliminado tantas unidades como se ha indicado.
		\coste Logaritmico respecto la cantidad de productos en el sistema.*/
	void quitar_unidad(string id, int cantidad);
	
	//Consultoras
	/** @brief Se escribe la cantidad de unidades del producto.
	  \pre El producto existe en el sistema.
	  \post Se ecribe por el canal de escritura predeterminada cuantas unidades
	  hay de ese producto.
		\coste Logaritmico respecto la cantidad de productos en el sistema. */
	void consultar_prod(string id);
	
	/** @brief Devuelve un booleano que dice si el producto se encuentra en el sistema.
	   \pre cierto
		 \post Se devuelve true si el elemento esta en el sistema o false si no esta.
		 \coste Logaritmico respecto a la cantidad de productos en el sistema. */
	bool eesta(string id);

	/** @brief Se escribe por el canal de salida predeterminado los productos que se encuentran en el inventario
	    por orden alfabetico.
			\pre cierto
			\post Se ha escrito por el canal de salida predeterminado los productos que estan en el sistema por orden
			alfabetico junto con la cantidad de elementos de cada uno.
			\coste Lineal respecto la cantidad de productos del sistema.*/
	void consul_inventario();
};

#endif
