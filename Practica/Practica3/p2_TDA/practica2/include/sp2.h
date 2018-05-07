/*

Un objeto de tipo Sopa_Letras contiene un conjunto de palabras dispuesto en la direcciones
verticales, horizontal o diagonal en un matriz dispersa. Además contiene una lista de palabras
no descubiertas por el usuario y una lista de palabras descubiertas por el usuario. Además la
sopa de letras contiene un título que recoge la temática de la misma. Para escribir en negrita
las acertadas puede usarse otras matriz dispersa indicando si la casilla es parte de una
descubierta o no.
Las operaciones mínimas que debería tener un objeto de tipo Sopa_Letras son las siguientes:
• Constructor por defecto.
• Operaciones de Consultas:
• Comprobar si una palabra a partir de una posición (fila,columna) y dirección se
encuentra en la sopa de letras.
• Comprobar si una palabra esta en la lista de palabras no descubiertas
• Comprobar si es posible poner una palabra en una posición (i,j) y dirección. Una
palabra puede colocarse si en cada casilla que ocupa tiene el valor por defecto,
o si no es así el carácter en la matriz debe coincidir con el carácter que
corresponda de la palabra.
• Obtener el número de palabras no descubiertas por el usuario
• Obtener el número de palabras descubiertas por el usuario
Operaciones de Modificación:
• Colocar una palabra en una posición y con una dirección concreta.
• Modificar una palabra en la matriz dispersa como acertada. Quitarla de
palabras no descubiertas y moverla a palabras descubiertas.
• Eliminar una palabra de la sopa de letras.
Operaciones de lectura y escritura de un flujo.
Cuando se imprime la sopa de letras aquellas casillas que tienen un valor por defecto se
escoge para imprimir un carácter aleatorio.

*/



 /**
  * @file sopa_letras.h
  * @brief Fichero cabecera del TDA Sopa de Letras
  * @brief Fichero cabecera para representar una sopa de letras 
  * @warning Este fichero no se puede modificar
  */

#ifndef _SOPALETRAS_H
#define _SOPALETRAS_H


#include "matriz_dispersa.h"
#include "VD.h"

#include <string>
#include <cstring>

using namespace std;
/**
  * @brief T.D.A. Sopa de Letras
  *
  * Una instancia @e s del tipo de datos abstracto @c Sopa_Letras es un objeto
  * de tipo Matriz_Dispersa, dos vectores dinamicos (VD) de tipo string y un string. 
  *
  * Un ejemplo de su uso:
  * @include prueba_sp.cpp
  *
  * @author Alejandro Garcia Perez
  * @date Noviembre 2017
  */


class Sopa_letras{

/**
   * @page repSopa_Letras Rep del TDA Sopa_Letras
   *
   * @section invSopa_Letras Invariante de la representación
   *
   * El invariante \e rep.m.vd[i].f != rep.m.default_value y que rep.no_descubiertas[i] != rep.descubiertas[i] 
   * @section faSopa_Letras Función de abstracción
   * Un objeto válido @e rep del TDA Sopa_Letras representa a una matriz infinita
   * en la cual solo se almacenan en memoria los datos que son distintos al valor por defecto.
   * (rep.m, rep.Nodescubiertas, rep.descubiertas. rep.nombre)
   *
*/  
private:
	string TITULO;

	Matriz_Dispersa m;

	VD<string> no_descubiertas;
	VD<string> descubiertas;


public:
   
	/**
    * @brief Constructor por defect 
 	*/
	Sopa_letras();

	/**
  	* @brief Esta
  	* @return Comprueba si una palabra está en la sopa de letras
  	*/ 

	bool Comprobar_Palabra(const string palabra, int fil, int col,const string dir)const;

	/**
  	* @brief Esta o no descubierta
  	* @return Comprueba si una palabra de la sopa de letras ha sido descubierta por el jugador
  	*/ 
	
	bool EstaDescubierta(const string palabra)const;

	/**
  	* @brief Bool Puedo Poner
  	* @return Comprueba si una palabra se puede poner en la sopa de letras
  	*/
	//Una palabra puede colocarse si en cada casilla que ocupa tiene el valor por defecto,
	//o si no es así el carácter en la matriz debe coincidir con el carácter que corresponda de la palabra
	bool PuedeInsertar(int fil, int col, const string dir, const string palabra)const;

	/**
  	* @brief Descubiertas
  	* @return Devuelve cuantas palabras han sido descubiertas.
  	*/
	int GetNumDescubiertas()const;
	
	/**
  	* @brief No Descubiertas
  	* @return Devuelve el numero de palabras que quedan por descubrir.
  	*/
	int GetNumNoDescubiertas()const;
	

	/**
  	* @brief Modifica y establece una palabra de la sopa de letras
  	*/
	void SetPalabra(string palabra, int fil, int col, const string dir);
	
	/**
  	* @brief Modifica una palabra cambiandola como acertada
  	*/
	//Modificar una palabra en la matriz dispersa como acertada. Quitarla de
	//palabras no descubiertas y moverla a palabras descubiertas.
	void Poner_Acertada(const string palabra);

		

	/**
  	* @brief Elimina una palabra de la sopa de letras.
  	*/
	void EliminarPalabra(string palabra, int fil, int col, const string dir);


		
	char CaracterAleatorio();	/*** Generar caracter aleatorio


/**
  * @brief Salida de una Sopa_letras a ostream
  * @param os stream de salida
  * @param s Sopa_letras a escribir
  * @post 
  */
  friend ostream& operator<< (ostream& os, const Sopa_letras& s);

/**
  * @brief Entrada de una Sopa_letras desde istream
  * @param is stream de entrada
  * @param s Sopa_letras que recibe el valor
  * @retval El Sopa_letras leído en r
  * @pre 
  */
  friend istream& operator>> (istream& is, Sopa_letras& s);




};

#endif