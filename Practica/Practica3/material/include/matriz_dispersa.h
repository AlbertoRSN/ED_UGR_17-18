/*

Con (∗, d) se representa todas aquellas casillas en la matriz que no están almacenadas en la
matriz dispersa y que tienen asociado el valor d (en nuestro caso d=0). Las tripletas se
ordenan de menor a mayor valor de fila, y a igualdad de fila, de menor a mayor columna.
Las operaciones mas relevantes de este T.D.A son:
• Constructor por defecto
• Constructor por parámetros: se le indica el valor por defecto
• Operadores de consulta:
• Obtener el elemento en la posición (i,j).
• Obtener la menor fila de la matriz
• Obtener la mayor fila de la matriz
• Obtener la menor columna de la matriz
• Obtener la mayor columna de la matriz
• Consultar el valor por defecto
• Indicar el número de casillas de la matriz que no tienen el valor por defecto
• Obtener el número de filas de la matriz
• Obtener el número de columnas de la matriz
• Operadores de modificación: modificar el elemento de la posición (i,j)
a un determinado valor. Este valor puede ser el valor por defecto, y en este caso se elimina
dicha casilla de memoria si existe en la matriz dispersa.
• Además se podría sobrecargar los operadores de escritura y lectura en flujos.

Esta version viene dada usando como tipo rep un vector dinámico implementado como template


*/


/**
  * @file VD.h
  * @brief Fichero cabecera del TDA Matriz_Dispersa 
  * @brief Fichero cabecera para representar una matriz dispersa de char
  * @warning Este fichero no se puede modificar
  */

#ifndef _MD
#define _MD

#include "VD.h"
#include <iostream>



/**
  * @brief Struct tripleta
  *
  * Una instancia @e t del tipo del tipo struct @c tripleta es un objeto
  * compuesto por 2 enteros indicando fila y columna en una matriz y un char  
  * para indicar el valor asociado
  * 
  * @author Alberto Rodriguez
  * @date Noviembre 2017
*/

struct tripleta{
	int fil,col;
	char valor;
};

template <class T>
class Matriz_Dispersa{


	private:
		VD<tripleta> m;		// vector dinámico con tripletas
		char default_value;


	public:
		

    /**
     * @brief Constructor por defecto de la clase. Crea una matriz vacia
     */

		Matriz_Dispersa();

		
		/**
    		* @brief Constructor por parametros de la clase. 
    		* @param valor_defecto Asigna un valor por defecto.
            * @return Crea la matriz dispersa con el valor por defecto
            * @pre valor_defecto debe ser distinto de cero
    	*/

    	Matriz_Dispersa(char valor_defecto);

		/**
  			* @brief Filas de la matriz
 			* @return Devuelve el numero de filas de la matriz
  		*/ 
		int NumFilas();const

		/**
  			* @brief Columnas de la matriz
  			* @return Devuelve el numero de columnas de la matriz
 		 */ 

		int NumColumnas();const

		/**
  			* @brief Elemento
  			* @return Devuelve el caracter asociado a una fila y a una columna
  		*/ 

		T GetEle(int fil, int col);const

		/**
  			* @brief Menor fila
  			* @return Devuelve la fila más pequeña de la matriz
 		 */

		int GetFilMenor();const

		/**
  			* @brief Menor columna de la matriz
  			* @return Devuelve la columna más pequeña de la matriz
  		*/ 

		int GetColMenor();const

		/**
  			* @brief Mayor fila de la matriz
  			* @return Devuelve a fila más grande de la matriz
 		*/ 

		int GetFilMayor();const

		/**
 			 * @brief Mayor columna de la matriz
 			 * @return Devuelve a columna más grande de la matriz
 		 */

		int GetColMayor();const

		/**
 			* @brief Valor por defecto de la matriz
 			* @return Devuelve el el valor por defecto de la matriz
  		*/ 

		char Default_value();const

		/**
		  * @brief Usadas de la matriz
		  * @return Devuelve el numero de elementos de la matriz que son distintos al valor por defecto.
  		*/ 

		int NumNotDefault();const

		/**
  		* @brief Modifica los objetos de la matriz dispersa;
  		*/

		void Set_value(int fil, int col, char ele);



  /**
  * @brief Sobrecarga del operador salida;Salida de una Matriz_Dispersa a ostream
  * @param os stream de salida
  * @param v Matriz_Dispersa a escribir
  * @post 
  */
  friend std::ostream& operator<<(std::ostream& os, const Matriz_Dispersa& otra);

};



//#include "matriz_dispersa.cpp"

#endif
