/**
  * @file VD.h
  * @brief Fichero cabecera del TDA Vector Dinamico
  * @brief Fichero cabecera para representar un vector dinamico de plantillas
  * @warning Este fichero no se puede modificar
  */
#ifndef _VD_H
#define _VD_H

/**
  * @brief T.D.A. Vector Racional
  *
  * Una instancia @e v del tipo de datos abstracto @c Vector Dinamico es un objeto
  * de tipo vector dinamico, compuestos por un puntero a template, dos enteros
  * que representan, respectivamente, el vector que contendrá los datos, el numero
  * de elementos almacenados y el numero de elementos reservados. 
  * Un ejemplo de su uso:
  * No se puede probar, es de tipo plantilla
  *
  * @author Alberto Rodriguez 
  * @date Diciembre 2017
  */

template <class T>

class VD{

 private:
  /**
   * @page repVD Rep del TDA VD
   *
   * @section invVector Invariante de la representación
   *
   * El invariante es \e rep.reservados<rep.n, que n>=0 y reservados>=0
   *
   * @section faVD Función de abstracción
   *
   * Un objeto válido @e rep del TDA VD representa a un puntero a template 
   *
   * (rep.datos, rep.n,rep.reservados)
   *
   */

  T *datos;
  int n; 		         //numero de elementos
  int reservados;    //n de memora reservada
  void resize(int nuevo_tam);

 public:

   /**
   * @brief Constructor por defecto de la clase. 
   * @param Crea un puntero a plantilla de tamaño 10
   */

  VD(int tam = 10);

   /**
   * @brief Constructor de copia de la clase
   * @param original.n esmnum de elementos a almacenar
   * @param original.reservados es memoria a reservar 
   */

  VD(const VD<T> &original);

   /**
   * @brief Destructor de la clase
   * @return Libera memoria del puntero datos
   */ 

  ~VD();
   
   /**
   * @brief size
   * @return Devuelve el tamaño del vector
   */ 

  int size()const;

   /**
   * @brief Sobrecarga del operador []
   * @param devuelve el elemento datos[i] 
   */  

  const T& operator[](const int i);


   /**
   * @brief introduce un nuevo elemento en el vector
   */

  void insertar(const T &dato, int pos);

    /**
   * @brief elimina un elemento en el vector que se encuentra
   * @brief en la posicion pos
   */

  void borrar(int pos);
 
   /**
   * @brief Sobrecarga del operador de asigancion
   * @param copia el vector original en el vector de la clase
   */
  VD<T> &operator=(const VD<T> &original);

};

#include "VD.cpp"

#endif

