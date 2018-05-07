/**
  * @file ConjuntoFrases.h
  * @brief Fichero cabecera del TDA ConjuntoFrases
  *
  */

#ifndef __CONJUNTOFRASES
#define __CONJUNTOFRASES

#include <iostream>
#include <string>
#include <vector>
#include "Frases.h"

using namespace std;

/**
   *  @brief T.D.A. ConjuntoFrases
   *
   * Una instancia del tipo de datos abstracto ConjuntoFrases es un objeto
   * del conjunto de las frases, compuesto por un valor que representa la frase origen 
   * junto con sus traducciones.
   *
   * Un ejemplo de su uso:
   * @include pruebatrad_test.cpp
   *
   * @author Alicia Rodríguez Sánchez
   * @date Noviembre 2016
*/

class ConjuntoFrases{

 private:
/**
   * @page repConjunto Rep del TDA ConjuntoFrases
   *
   * @section invConjunto Invariante de la representación
   *
   * El invariante es \e rep.CF[CF.size()]!=0 , tiene al menos n elementos
   *
   * @section faConjunto Función de abstracción
   *
   * Un objeto válido @e rep del TDA ConjuntoFrases representa al valor
   *
   * rep.CF[CF.size()]
   *
*/


  vector <Frase> CF;/**<Conjunto de frases */
   

 public:

/**
   * @brief Devuelve cuantas frases hay
   *
   * @return Devuelve el tamaño del vector de Frases
   *
*/
	int Size();
	

/**
   * @brief Añade una frase
   *
   * @param i : nueva frase a añadir en el vactor
   *
   * @return Añade una nueva frase al vector del conjunto frases
   *
   * @post Queda añadida una nueva frase en el vector de frases
   *
*/
	void Aniadir(Frase& i);


/**
   * @brief Devuelve un conjunto de frases
   *
   * @return Devuelve un vector de frases
   *
*/
	vector <Frase> GetCF();



/**
   * @brief Indica si una frase introducida es una frase origen que esta o no
   *
   * @param orig_a_buscar : frase origen a buscar 
   *
   * @return Devuelve true o false 
   *
*/
	bool Esta(string orig_a_buscar);


/**
   * @brief Obtiene las traducciones de una frase origen
   *
   * @pre frase_origen debe existir en el vector de frases
   *
   * @param frase_origen : frase a traducir
   *
   * @return Devuelve un vector de traducciones
   * 
*/
	Frase GetTraducciones(string frase_origen);


/**
   * @brief Busca una subcadena en la frase origen
   *
   * @pre subcadena_a_buscar debe existir en alguna de las frases origen
   *
   * @param subcadena_a_buscar : es la subcadena a buscar en la frase origen
   *
   * @return Devuelve un conjunto de frases que contengan esa subcadena, junto con sus traducciones.
*/	
	ConjuntoFrases Contenga(string subcadena_a_buscar);


/**
   * @brief Entrada de un conjunto de frases desde istream
   *
   * @param inputs stream de entrada
   *   
   * @param cf ConjuntoFrases que recibe el valor
   *   
   * @return La referencia al istream
   *   
   * @pre La entrada es un fichero separado por ";" con una frase origen y al menos una frase de traduccion 
   *
*/
	friend ifstream& operator>> (ifstream& inputs, ConjuntoFrases& cf);


/**
  * @brief Salida de una traduccion a ostream 	
  *
  * @param os stream de salida
  *
  * @param cf ConjuntoFrases a escribir
  *
  * @post Se obtiene en la frase origen con sus traducciones
  *  
*/
	friend ostream& operator<< (ostream & os, ConjuntoFrases& cf);


};

//#include "ConjuntoFrases.cpp"

#endif
