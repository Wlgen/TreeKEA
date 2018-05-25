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
	*/

class inventario{
	private:
	map<string, int> inv;
	
	public:
	//Constructoras
	
	/** @brief Se crea una variable inventario con ningun producto dado de alta. */
	inventario();
	
	//Modificadoras
	
	/** @brief Se añade un nuevo producto al sistema.  
	  \Pre El producto no existia en el sistema.
	  \Post El producto se ha dado de alta en le sistema con 0 unidades. */
	void poner_prod(string id);
	 
	
	/** @brief Se elimina un producto existente del sistema.
	  \Pre El producto existe en el sistema y tiene 0 unidades.
	  \Post El producto se ha eliminado del sistema. */
	void quitar_prod(string id);
	 
	
	/** @brief Se suma a las unidades existentes la cantidad indicada.
	  \Pre Cierto.
	  \Post Se ha sumado la cantidad indicada de unidades a la cantidad que habia de el producto
	  indicado. */
	void poner_unidad(string id, int cantidad);
	
	
	/** @brief Se quitan tantas unidades del producto como se indican.
	  \Pre Cierto.
	  \Post Se han eliminado, como mucho, tantas unidades como se ha indicado.
	  Si todavia quedan mas por eliminar simplemente se queda en 0. */
	void quitar_unidad(string id, int cantidad);
	
	//Consultoras
	/** @brief Se escribe la cantidad de unidades del producto.
	  \Pre El producto existe en el sistema.
	  \Post Se ecribe por el canal de escritura predeterminada cuantas unidades
	  hay de ese producto */
	void consultar_prod(string id);
	
	/** @brief Devuelve un booleano que dice si el producto se encuentra en el sistema. */
	bool eesta(string id);

	/** @brief Se escribe por el canal de salida predeterminado los productos que se encuentran en el inventario
	    por orden alfabetico */
	void consul_inventario();
};

#endif
