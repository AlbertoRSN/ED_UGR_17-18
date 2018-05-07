/**
  * @file Frases.h
  * @brief Fichero cabecera del TDA Frase
  *
  */

#ifndef __FRASE
#define __FRASE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
  *  @brief T.D.A. Frases
  *
  * Una instancia del tipo de datos abstracto Frase es un objeto
  * compuesto por un valor que representa la frase origen 
  * junto con sus traducciones.
  *
  * Un ejemplo de su uso:
  * @include pruebatrad_test.cpp
  *
  * @author Alicia Rodríguez Sánchez
  * @date Noviembre 2016
  */



class Frase{

 private:

/**
  * @page repConjunto Rep del TDA Frase
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.destino.size()!=0
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Frase representa al valor
  *
  * (rep.origen,rep.destino[rep.destino.size()])
  *
  */

  string origen; /**<frase origen*/
  vector<string> destino; /**<vector de traducciones*/

 public:

/**
   * @brief Entrada de una frase desde istream
   * @param inputs stream de entrada
   * @param f Frase que recibe el valor
   * @return La referencia al istream
   * @pre La entrada de una cadena separada por ";" con una frase origen 
*/
	friend ifstream& operator>> (ifstream& inputs, Frase& f);


/**
   * @brief Devuelve una frase origen
   * @pre Debe haber una frase origen escrita
   *
   * @return Devuelve la frase "origen" 
*/
  	string GetFraseOrigen(); 


/**
   * @brief Devuelve las traducciones de una frase
   *
   * @pre Debe haber al menos una traduccion en el vector de string "destino"
   *
   * @return Devuelve las traducciones 
   *
*/
  	vector<string> GetDestino();


/**
   * @brief Asigna la frase "origen"
   *
   * @param orig : string que asigna al "origen" de una instancia de Frase
   *
   * @return Asigna el "origen" 
   *
*/
	void SetOrigen(string orig);


/**
   * @brief Asigna las traducciones
   *
   * @param traducciones : vector de string que se asigna al vector "destino" de una instancia de Frase
   *
   * @return Asigna un vector de string al vector "destino" 
   *
*/
	void SetDestino(vector <string> traducciones);


/**
   * @brief Añade un elemento al vector de traducciones 
   *
   * @param c : string que se asigna al vector "destino" 
   *
   * @return Añade un elemento (string) al vector de traducciones "destino" 
   *
   * @post El vector "destino" contiene un nuevo elemento
   *
*/
	void AniadirDestino(string c);


/**
   * @brief Borra las traducciones
   *
   * @return Borra las traducciones(destino) de una frase
   *
*/
	void Borrar();

};

//#include "Frases.cpp"

#endif

