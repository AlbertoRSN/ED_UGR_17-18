/**
 * @matriz_dispersa.h
 * @brief Fichero cabecera del TDA Matriz Dispersa
 *
 */

#ifndef __MATRIZ_DISPERSA
#define __MATRIZ_DISPERSA

#include <iostream>
#include <cstring>


using namespace std;

/**
 *  @brief TRIPLETA 
 *
 * Una tripleta va a ser un conjunto de 3 valores (2 int y un char) almacenados en cad posicion de un vector dinamico.
 *
 *  @brief T.D.A. Matriz Dispersa
 *
 * Una instancia del tipo de datos matriz_dispersa es un objeto del conjunto Matriz_Dispersa
 * compuesto por un numero de filas, un numero de columnas, valor por defecto y una instancia de vector dinamico
 * de Tripletas .
 *
 * @author Alberto Rodriguez Santana
 * @date Noviembre 2017
 */

 Template <class T>
    struct Tripleta{
      int fil, col;
     char dato;
    };

/**
 *  @brief T.D.A. Matriz Dispersa
 *
 * Una instancia del tipo de datos matriz_dispersa es un objeto del conjunto Matriz_Dispersa
 * compuesto por un numero de filas, un numero de columnas, valor por defecto y una instancia de vector dinamico
 * de Tripletas .
 *
 * @author Alberto Rodriguez Santana
 * @date Noviembre 2017
 */


Template <class T>
class Matriz_Dispersa{
    
private:
    /**
     * @page repConjunto Rep del TDA Matriz Dispersa
     *
     * @section invConjunto Invariante de la representaciÛn
     *
     * El invariante es r.valor_por_defecto != r.m[i] para todo 0 < i < r.m.size() 
     *
     * @section faConjunto FunciÛn de abstracciÛn
     *
     * Un objeto valido @e rep del TDA Racional representa al valor
     *
     * (rep.num,rep.den)
     *
     */

    VD<Tripleta> m; /**< Vector dinamico de datos */
    char valor_defecto; /**< valor por defecto */
    
public:
    
    /**
     * @brief Constructor por defecto de la clase. Crea una matriz vacia
     */
    Matriz_Dispersa();
    
    /**
     * @brief Constructor de la clase
     * @param n valor por defecto
     * @return Crea la matriz dispersa con el valor por defecto
     * @pre n debe ser distinto de cero
     */
    Matriz_Dispersa(int n);
    
    /**
     * @brief Metodo consultor de Matriz Dispersa
     * @param i valor de la fila
     * @param j valor de la columna
     * @return Devuelve elemento (dato) en la posicion (i,j) de la matric dispersa
     */
    T Get(int i, int j) const;

    /**
     * @brief Metodo modificador de Matriz Dispersa
     * @param i valor de la fila
     * @param j valor de la columna
     * @param nuevo valor a introducir en la matriz si es distinto de valor_defecto
     */
    void Set(int i, int j, const T &nuevo){

    /**
     * @brief Metodo para obtener la menor fila de la matriz
     * @return numdro de la fila menor
     */
    int menorFila() const;

    /**
     * @brief Metodo para obtener la mayor fila de la matriz
     * @return numdro de la fila mayor
     */
    int mayorFila() const;

    /**
     * @brief Metodo para obtener la menor columna de la matriz
     * @return numdro de la columna menor
     */
    int menorColumna() const;

    /**
     * @brief Metodo para obtener la mayor columna de la matriz
     * @return numero de la columna mayor
     */
    int mayorColumna() const;

     /**
     * @brief Metodo para saber el valor por defecto 
     * @return valor por defecto
     */
    char getValorDefecto() const;

    /**
     * @brief Metodo para saber el numero de casillas sin valor por defecto
     * @return contador de casillas
     */
    int numCasillasNoDefecto() const;

    /**
    * @brief Salida de una matriz dispersa a ostream
    * @param os stream de salida
    * @param r Racional a escribir
    * @post Se obtiene \a os la cadena VD<T> (i,j,valor)
    *   del numerador y denominador de \a r
    */
    friend ostream& operator<< (ostream& os, const Matriz_Dispersa& m);

    /**
     * @brief Entrada de una matriz Dispersa desde istream
     * @param is stream de entrada
     * @param r Racional que recibe el valor
     * @retval La matriz dispersa leido en m
     */
     friend istream& operator>> (istream& is, Matriz_Dispersa& m);



};

#endif
